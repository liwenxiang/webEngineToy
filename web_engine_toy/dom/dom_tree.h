#ifndef NAME_CODEBOY_WEB_ENGINE_TOY_DOM_DOMTREE
#define NAME_CODEBOY_WEB_ENGINE_TOY_DOM_DOMTREE

#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

#include <boost/noncopyable.hpp>
namespace name {
namespace codeboy {
namespace web_engine_toy {
namespace dom {


class Node : public boost::noncopyable {
public:
    virtual void AddChild(Node* child);
    virtual const void ToString(std::ostringstream& str, int space);
protected:
    std::vector<Node*> mChildren;
};

class Text : public Node{
public:
    Text(const std::string& content);
    virtual const void ToString(std::ostringstream& str, int space);
private:
    std::string mContent;
};

class Element : public Node{
public:
    Element(const std::string& tagName);
    void AddAttr(const std::string& key, const std::string& value);
    virtual const void ToString(std::ostringstream& str, int space);
private:
    std::string mTagName;
    std::unordered_map<std::string, std::string> mAttrs;
};

typedef Node DomTree;

} } } } 
#endif

