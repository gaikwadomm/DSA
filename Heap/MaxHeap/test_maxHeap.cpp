#include "maxHeap.cpp"
#include <cassert>
#include <sstream>
#include <iostream>

// Helper to capture cout output
std::string captureOutput(void (*func)()) {
    std::streambuf* oldCout = std::cout.rdbuf();
    std::ostringstream out;
    std::cout.rdbuf(out.rdbuf());
    func();
    std::cout.rdbuf(oldCout);
    return out.str();
}

void test_insert_and_display() {
    MaxHeap h(5);
    h.insert(10);
    h.insert(30);
    h.insert(20);

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("Val in Heap are : ") != std::string::npos);
    assert(output.find("30") != std::string::npos);
    assert(output.find("20") != std::string::npos);
    assert(output.find("10") != std::string::npos);
}

void test_heap_overflow() {
    MaxHeap h(2);
    h.insert(5);
    h.insert(15);

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.insert(25);
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("Heap Overflow") != std::string::npos);
}

void test_deleteVal() {
    MaxHeap h(3);
    h.insert(40);
    h.insert(20);
    h.insert(30);

    h.deleteVal();

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("40") == std::string::npos); // 40 should be deleted
    assert(output.find("30") != std::string::npos);
    assert(output.find("20") != std::string::npos);
}

void test_delete_empty() {
    MaxHeap h(2);
    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.deleteVal();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("Heap is Empty") != std::string::npos);
}

void test_display_empty() {
    MaxHeap h(2);
    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("Heap is Empyt") != std::string::npos);
}

// Additional edge case tests

void test_insert_duplicate_values() {
    MaxHeap h(5);
    h.insert(10);
    h.insert(10);
    h.insert(10);

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    int count = 0;
    size_t pos = 0;
    while ((pos = output.find("10", pos)) != std::string::npos) {
        ++count;
        pos += 2;
    }
    assert(count == 3);
}

void test_insert_negative_values() {
    MaxHeap h(4);
    h.insert(-10);
    h.insert(-20);
    h.insert(-5);

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("-5") != std::string::npos);
    assert(output.find("-10") != std::string::npos);
    assert(output.find("-20") != std::string::npos);
}

void test_delete_until_empty() {
    MaxHeap h(3);
    h.insert(100);
    h.insert(50);
    h.insert(25);

    h.deleteVal();
    h.deleteVal();
    h.deleteVal();

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("Heap is Empyt") != std::string::npos);
}

void test_insert_delete_alternate() {
    MaxHeap h(2);
    h.insert(1);
    h.deleteVal();
    h.insert(2);
    h.deleteVal();

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("Heap is Empyt") != std::string::npos);
}

void test_single_element_heap() {
    MaxHeap h(1);
    h.insert(99);

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("99") != std::string::npos);

    h.deleteVal();

    out.str("");
    std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    output = out.str();
    assert(output.find("Heap is Empyt") != std::string::npos);
}

void test_full_capacity_insert_delete() {
    MaxHeap h(3);
    h.insert(5);
    h.insert(15);
    h.insert(25);

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    h.insert(35); // Should overflow
    std::cout.rdbuf(oldCout);

    std::string output = out.str();
    assert(output.find("Heap Overflow") != std::string::npos);

    h.deleteVal();
    h.deleteVal();
    h.deleteVal();

    out.str("");
    std::cout.rdbuf(out.rdbuf());
    h.display();
    std::cout.rdbuf(oldCout);

    output = out.str();
    assert(output.find("Heap is Empyt") != std::string::npos);
}

int main() {
    test_insert_and_display();
    test_heap_overflow();
    test_deleteVal();
    test_delete_empty();
    test_display_empty();
    test_insert_duplicate_values();
    test_insert_negative_values();
    test_delete_until_empty();
    test_insert_delete_alternate();
    test_single_element_heap();
    test_full_capacity_insert_delete();
    std::cout << "All tests passed!\n";
    return 0;
}