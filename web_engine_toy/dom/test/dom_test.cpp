#include <iostream>
#include <sstream>
#include <muduo/base/Logging.h>
#include <gtest/gtest.h>

#include "web_engine_toy/dom/dom_tree.h"

namespace name {
namespace codeboy {
namespace web_engine_toy {
namespace dom {

using std::string;
using std::ostringstream;



TEST(DomTreeTest, DomTreeInitTest)
{
    LOG_INFO << "pid = " << getpid() << " begin to run";
    EXPECT_FALSE(false);

    Node* head = new Text("html");
    Element* p = new Element("a");
    p->AddAttr("href", "http://abc/");
    p->AddAttr("color", "yellow");
    Node* txt = new Text("def");
    Node* txt2 = new Text("Head");

    head->AddChild(p);
    p->AddChild(txt);
    head->AddChild(txt2);

    ostringstream oss;
    head->ToString(oss, 0);
    LOG_INFO << "\n" << oss.str();
    string out(
            "html\n"
            "--Tagname is a Key colorValue yellow Key hrefValue http://abc/\n"
            "----def\n"
            "--Head\n");
    ASSERT_EQ(out, oss.str());

}

} } } } 
