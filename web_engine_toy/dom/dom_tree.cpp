#include <web_engine_toy/dom/dom_tree.h>

namespace name {
namespace codeboy {
namespace web_engine_toy {
namespace dom {

using std::string;
using std::ostringstream;

const void Node::ToString(ostringstream& str, int space) {
    str << "\n";
    for(auto iter = mChildren.begin(); iter != mChildren.end(); ++iter) {
        (*iter)->ToString(str, space + 1);
    }
}
void Node::AddChild(Node* child) {
    mChildren.push_back(child);
}

Text::Text(const std::string& content): 
    mContent(content){

}
const void Text::ToString(ostringstream& str, int space) {
    for (int i = 0; i < space; i++) {
        str << "--";
    }
    str << mContent;
    Node::ToString(str, space);
}
Element::Element(const std::string& tagName)
    :mTagName(tagName) {
}

void Element::AddAttr(const std::string& key, const std::string& value) {
    //override old kv
    mAttrs[key] = value;
}
const void Element::ToString(ostringstream& str, int space) {
    for (int i = 0; i < space; i++) {
        str << "--";
    }
    str << "Tagname is ";
    str << mTagName;
    for(auto iter = mAttrs.begin(); iter != mAttrs.end(); ++iter) {
        str << " Key ";
        str << iter->first;
        str << "Value ";
        str << iter->second;
    }
    Node::ToString(str, space);
}

} } } } 

