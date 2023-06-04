#ifndef GENERIC_TEST_CHECK_FUNCTIONS_HPP_
#define GENERIC_TEST_CHECK_FUNCTIONS_HPP_
#include <gtest/gtest.h>
#include <memory>
#include <string>

template<typename T>
void ObjectInitCheck(const std::string& name, const std::unique_ptr<T>& ptr) noexcept {
	EXPECT_NE(ptr, nullptr) << "Failed to initialise the object " << name << ".";
}

template<typename T>
void ObjectNullCheck(const std::string& name, const std::unique_ptr<T>& ptr) noexcept {
	EXPECT_EQ(ptr, nullptr) << "The object " << name << " isn't null.";
}
#endif
