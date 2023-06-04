#include <gtest/gtest.h>
#include <WindowWin.hpp>
#include <memory>
#include <GenericCheckFunctions.hpp>

class WindowWinTest : public ::testing::Test {
protected:
	static inline std::unique_ptr<Window> s_window;
};

TEST_F(WindowWinTest, InitTest) {
	s_window = std::make_unique<WindowWin>();

	ObjectInitCheck("s_window", s_window);

	EXPECT_EQ(s_window->GetSummation(3, 4), 7) << "The summation isn't correct.";
}
