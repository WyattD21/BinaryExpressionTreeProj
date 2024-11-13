#ifndef BINARY_EXPRESSION_TREE_H
#define BINARY_EXPRESSION_TREE_H

#include "binaryTree.h"
#include <stack>
#include <string>
#include <sstream>


class binaryExpressionTree : public binaryTreeType<std::string> {
public:
    binaryExpressionTree() : binaryTreeType() {}

    bool search(const std::string& searchItem) const override {
        return false; 
    }

    void insert(const std::string& insertItem) override {
    }

    void deleteNode(const std::string& deleteItem) override {
    }

    void buildExpressionTree(const std::string& postfixExpr) {
        destroyTree();  
        std::stack<nodeType<std::string>*> nodeStack;
        std::istringstream tokens(postfixExpr);
        std::string token;

        while (tokens >> token) {
            if (isdigit(token[0])) { 
                auto* newNode = new nodeType<std::string>();
                newNode->info = token; 
                nodeStack.push(newNode);
            }
            else if (isOperator(token)) { 
                auto* newNode = new nodeType<std::string>();
                newNode->info = token;  

                if (!nodeStack.empty()) {
                    newNode->rLink = nodeStack.top();
                    nodeStack.pop();
                }
                if (!nodeStack.empty()) {
                    newNode->lLink = nodeStack.top();
                    nodeStack.pop();
                }
                nodeStack.push(newNode);
            }
        }

        if (!nodeStack.empty()) {
            root = nodeStack.top();
            nodeStack.pop();
        }
    }

    double evaluateExpressionTree() {
        return evaluateExpressionTree(root);
    }

private:
    bool isOperator(const std::string& op) const {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }

    double evaluateExpressionTree(nodeType<std::string>* p) {
        if (!p->lLink && !p->rLink) {  
            return std::stod(p->info);
        }

        double left = evaluateExpressionTree(p->lLink);
        double right = evaluateExpressionTree(p->rLink);
        std::string op = p->info;

        if (op == "+") return left + right;
        if (op == "-") return left - right;
        if (op == "*") return left * right;
        if (op == "/") return left / right;

        return 0;  
    }
};

#endif 
