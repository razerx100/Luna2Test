#include <gtest/gtest.h>
#include <WindowWin.hpp>
#include <memory>
#include <GenericCheckFunctions.hpp>

class WindowWinTest : public ::testing::Test {
protected:
	static inline std::unique_ptr<Window> s_window;
};

TEST_F(WindowWinTest, InitTest) {
	s_window = std::make_unique<WindowWin>(1280u, 720u, "Luna");

	ObjectInitCheck("s_window", s_window);

	s_window->SetWindowTitle("Hello world.");
}
