//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "functions.h"

const string INPUT_FILE("wordlist.txt");

TEST_CASE("string processing") {
  SUBCASE("empty string") {
    CHECK(toupper("") == string(""));
    CHECK(tolower("") == string(""));
    CHECK(digits("") == 0);
    CHECK(punctuation("") == 0);
    CHECK(vowels("") == 0);
  }

  SUBCASE("simple strings") {
    CHECK(toupper("abc") == string("ABC"));
    CHECK(tolower("ABC") == string("abc"));
    CHECK(digits("123") == 3);
    CHECK(punctuation(",.;") == 3);
    CHECK(vowels("aeiou") == 5);
  }

  SUBCASE("harder strings") {
    CHECK(toupper("AbCd1.2,3;") == string("ABCD1.2,3;"));
    CHECK(tolower("AbCd1.2,3;") == string("abcd1.2,3;"));
    CHECK(digits("AbCd1.2,3;") == 3);
    CHECK(punctuation("AbCd1.2,3;") == 3);
    CHECK(vowels("AbCd1.2,3;") == 1);
  }
}

TEST_CASE("vector processing") {
  SUBCASE("empty file") {
    vector<string> vtest = readFile("nothere.txt");
    CHECK(vtest.size() == 0);
  }

  SUBCASE("wordlist file") {
    vector<string> vtest = readFile(INPUT_FILE);
    CHECK(vtest.size() == 50);
    CHECK(allCharacters(vtest) == 376);
    CHECK(allDigits(vtest) == 3);
    CHECK(allPunctuation(vtest) == 3);
    CHECK(allVowels(vtest) == 127);
  }
}
