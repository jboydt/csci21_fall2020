//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "bank_account.h"

TEST_CASE("default constructor") {
   BankAccount acct;

   CHECK(acct.getBalance() == doctest::Approx(0.0));
   CHECK(acct.getAccountNumber() == 0);
   CHECK(acct.toString() == string("Account #0, Current balance $0.00"));

   acct.deposit(10.1);
   CHECK(acct.getBalance() == doctest::Approx(10.1));
   CHECK(acct.toString() == string("Account #0, Current balance $10.10"));

   CHECK(acct.withdraw(10.0) == true);
   CHECK(acct.getBalance() == doctest::Approx(0.1));
   CHECK(acct.toString() == string("Account #0, Current balance $0.10"));

   CHECK(acct.withdraw(0.2) == false);
   CHECK(acct.getBalance() == doctest::Approx(0.1));
   CHECK(acct.toString() == string("Account #0, Current balance $0.10"));
}

TEST_CASE("account number only") {
  BankAccount acct(9876);

  CHECK(acct.getBalance() == doctest::Approx(0.0));
  CHECK(acct.getAccountNumber() == 9876);
  CHECK(acct.toString() == string("Account #9876, Current balance $0.00"));
}

TEST_CASE("account number and balance") {
  BankAccount acct(1.2, 9876);

  CHECK(acct.getBalance() == doctest::Approx(1.2));
  CHECK(acct.getAccountNumber() == 9876);
  CHECK(acct.toString() == string("Account #9876, Current balance $1.20"));
}
