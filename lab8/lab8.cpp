//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
using std::to_string;

#include "inventory.h"

TEST_CASE("item") {
  Item i1 = {"Item 2", 0.05, 3};
  Item i2 = {"Item 1", 0.10, 1};
  Item i3 = {"Item 3", 0.25, 2};

  CHECK(compareByName(i1, i2) == false);
  CHECK(compareByName(i1, i3) == true);

  CHECK(compareByPrice(i2, i1) == false);
  CHECK(compareByPrice(i2, i3) == true);

  CHECK(compareByQuantity(i3, i1) == true);
  CHECK(compareByQuantity(i3, i2) == false);

  CHECK(itemToString(i1) == string("Item 2, $0.05, 3 available"));
}

TEST_CASE("inventory") {
  Item i1 = {"Item 2", 0.05, 3};
  Item i2 = {"Item 1", 0.10, 2};
  Item i3 = {"Item 3", 0.25, 1};

  Inventory inv;

  SUBCASE("basic functionality") {
    CHECK(inv.getItemCount() == 0);
    CHECK(inv.toString() == string(""));

    CHECK(inv.addItem(i1) == true);
    CHECK(inv.getItemCount() == 1);
    CHECK(inv.hasItem(i1.name) == true);
    CHECK(inv.updateItem(i1.name, "Item 20", 1.05, 30) == true);
    CHECK(inv.toString() == string("[1] Item 20, $1.05, 30 available\n"));

    CHECK(inv.removeItem("Item 20") == true);
    CHECK(inv.getItemCount() == 0);
    CHECK(inv.toString() == string(""));
  }

  SUBCASE("has a few items") {
    CHECK(inv.addItem(i1) == true);
    CHECK(inv.addItem(i2) == true);
    CHECK(inv.addItem(i3) == true);

    CHECK(inv.getItemCount() == 3);

    CHECK(inv.hasItem(i1.name) == true);
    CHECK(inv.hasItem(i2.name) == true);
    CHECK(inv.hasItem(i3.name) == true);

    CHECK(inv.toString() ==
      string("[1] Item 2, $0.05, 3 available\n[2] Item 1, $0.10, 2 available\n[3] Item 3, $0.25, 1 available\n"));

    CHECK(inv.updateItem(i1.name, "Item 20", 1.05, 30) == true);
    CHECK(inv.updateItem(i2.name, "Item 10", 1.10, 20) == true);
    CHECK(inv.updateItem(i3.name, "Item 30", 1.25, 10) == true);

    CHECK(inv.toString() ==
      string("[1] Item 20, $1.05, 30 available\n[2] Item 10, $1.10, 20 available\n[3] Item 30, $1.25, 10 available\n"));

    CHECK(inv.removeItem("Item 20") == true);
    CHECK(inv.removeItem("Item 10") == true);
    CHECK(inv.removeItem("Item 30") == true);
    CHECK(inv.getItemCount() == 0);
    CHECK(inv.toString() == string(""));
  }

  SUBCASE("stress test") {
    for (size_t i = 1; i <= 100; i++) {
      Item item = {"Item " + to_string(i), 1.0, 1};
      CHECK(inv.addItem(item) == true);
    }
    CHECK(inv.getItemCount() == 100);
    for (size_t i = 1; i <= 100; i++) {
      CHECK(inv.removeItem("Item " + to_string(i)));
    }
    CHECK(inv.getItemCount() == 0);
  }
}
