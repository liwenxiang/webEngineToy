#include <iostream>
#include <muduo/base/Logging.h>
#include <gtest/gtest.h>

#include "web_engine_toy/dom/dom_tree.h"

namespace name {
namespace codeboy {
namespace web_engine_toy {
namespace dom {


TEST(firstTest, abs)
{
    DomTree dom;
    LOG_INFO << "pid = " << getpid() << " begin to run";
    EXPECT_FALSE(false);
}

} } } } 

// int main(int argc, char** argv) {
//      ::testing::InitGoogleTest(&argc, argv);
//      return RUN_ALL_TESTS();
// }
