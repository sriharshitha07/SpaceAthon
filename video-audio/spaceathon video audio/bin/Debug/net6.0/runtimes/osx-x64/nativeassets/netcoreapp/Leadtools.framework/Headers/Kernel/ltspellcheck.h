//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTSPELLCHECK_H)
#define LTSPELLCHECK_H

#include "lttyp.h"

#if !defined(L_LTSPELLCHECK_CLASS)
#  if !defined(FOR_UNIX)
#     define L_LTSPELLCHECK_CLASS __declspec(dllexport)
#  else
#     define L_LTSPELLCHECK_CLASS 
#  endif
#endif

#define L_LTSPELLCHECK_API LT_EXPORTED

#include "lterr.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

// ----------------------------------------------
// Defines and enums
// ----------------------------------------------
#include "ltocrEnums.h"

#define L_SpellCheckerResult_SuggestionsCount 20
#define L_SpellChecker_MaximumWordLength 256

// ----------------------------------------------
// Handles
// ----------------------------------------------

L_DECLARE_HANDLE(L_SpellChecker);

// ----------------------------------------------
// Structures
// ----------------------------------------------

struct L_SpellCheckerOptions
{
   L_UINT StructSize; // Size of this structure
   L_BOOL IgnoreHtml; // Ignore words with html tags in them
   L_BOOL IgnoreWordsWithDigits; // Ignore words with digits in them
   L_BOOL IgnoreAllCapsWords; // Ignore all caps words (only for Latin languages)
   L_UINT MaximumWordLength; // If word is bigger than this then it will not be spelled
   L_BOOL OcrMode; // For internal use
   L_UINT MaximumEditDistance; // For internal use. Ignores any suggestion with edit distance bigger than this
   L_BOOL EnableTraining; // For internal use
   L_BOOL BusinessCardMode; // For internal use of the business card reader toolkit
   L_UINT MinimumWordLength; // For internal use of the business card reader toolkit
   L_UINT MultipleTermSplits; // For splitting input term two, three or more ways, 2 is default
   L_BOOL IcrMode; // For internal use 
};
typedef struct L_SpellCheckerOptions L_SpellCheckerOptions;

struct L_SpellCheckerResult
{
   L_UINT StructSize; // Size of this structure
   L_WCHAR Word[L_SpellChecker_MaximumWordLength]; // Original word
   L_BOOL IsWordCorrect; // Word is correct, no suggestions, otherwise, look at suggestions
   L_WCHAR Suggestions[L_SpellCheckerResult_SuggestionsCount][L_SpellChecker_MaximumWordLength]; // Suggestions
   L_UINT SuggestionCount; // Number of valid suggestions, if 0, word is wrong but no suggestions
   L_BOOL IsUserWord;  // The word was found in the user list
   L_INT MinimumEditDistance; // for internal use. 
   L_INT SuggestionsWeights[L_SpellCheckerResult_SuggestionsCount]; // for internal use. 
   L_INT SuggestionsEditDistances[L_SpellCheckerResult_SuggestionsCount]; // for internal use. 
};
typedef struct L_SpellCheckerResult L_SpellCheckerResult;

struct L_SpellCheckerRubbishWord
{
   L_UINT StructSize;
   L_DOUBLE Likelihood;
   L_BOOL IsAllAlpha;
   L_BOOL IsAllUpperDigit;
   L_BOOL IsRubbish;
   L_DOUBLE TriGramAverage;
   L_DOUBLE TriGramMaximum;
   L_DOUBLE TriGramMinimum;
   L_DOUBLE BiGramAverage;
   L_DOUBLE BiGramMaximum;
   L_DOUBLE BiGramMinimum;
};
typedef struct L_SpellCheckerRubbishWord L_SpellCheckerRubbishWord;

// ----------------------------------------------
// Callbacks
// ----------------------------------------------

// ----------------------------------------------
// Functions
// ----------------------------------------------
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_Create(L_SpellChecker* spellChecker, L_OcrLanguage language, const L_TCHAR* dictionaryFileName);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_Destroy(L_SpellChecker spellChecker);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_GetOptions(L_SpellChecker spellChecker, L_SpellCheckerOptions* options);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_SetOptions(L_SpellChecker spellChecker, const L_SpellCheckerOptions* options);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_GetLanguage(L_SpellChecker spellChecker, L_OcrLanguage* language);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_Spell(L_SpellChecker spellChecker, const L_WCHAR* word, L_SpellCheckerResult* result, const L_SpellCheckerOptions* options);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_IsWordCorrect(L_SpellChecker spellChecker, const L_WCHAR* word, L_SpellCheckerResult* result, const L_SpellCheckerOptions* options);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_GetSuggestion(const L_SpellCheckerResult* result, L_UINT index, L_WCHAR* suggestion);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_GetRubbishWord(const L_WCHAR* word, L_SpellCheckerRubbishWord* result);

// User words dictionary support
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_AddUserWord(L_SpellChecker spellChecker, const L_WCHAR* word);
// You should pass double null terminated string for the 'words' parameter
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_AddUserWords(L_SpellChecker spellChecker, const L_WCHAR* words);
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_RemoveUserWord(L_SpellChecker spellChecker, const L_WCHAR* word);
// if words is NULL, removes all
// You should pass double null terminated string for the 'words' parameter
L_LTSPELLCHECK_API L_INT EXT_FUNCTION L_SpellChecker_RemoveUserWords(L_SpellChecker spellChecker, const L_WCHAR* words);

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTSPELLCHECK_H)
