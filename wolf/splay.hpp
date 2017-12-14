#pragma once

#include <cassert>

namespace wolf::structs {

    template<typename T, typename Node>
    struct BaseNode {
        Node* left;
        Node* right;
        Node* parent;
        T val;
        typedef T key_type;
        BaseNode(const T& val):val(val), left(nullptr), right(nullptr), parent(nullptr) {}
        //~BaseNode() { delete left; delete right; }
        bool whichChild(const Node* node) const { return left == node ? false : true; }
        void change(const Node* from, Node* into) { ((from == left) ? left : right) = into; }
        void makeOrphan() { parent = nullptr; }
        void abandon() { left = right = nullptr; }
    };

    template<typename Node, typename AfterRotate>
    struct Splay {
        typedef typename Node::key_type key_type;

        Splay(AfterRotate after):root(nullptr), after(after) {}
        bool insertNode(Node* addon) {
            if(root) {
                auto node = findProximity(addon->val);
                if(node->val == addon->val)
                    return false;

                auto& below = (addon->val < node->val) ? node->left : node->right;
                below = addon, addon->parent = node;
                splayAndRoot(addon);
            }
            else 
                root = addon;
            return true;
        }

        bool erase(const key_type& el) {
            auto node = findProximity(el);
            if(node == nullptr || node->val != el)
                return false;

            splayAndRoot(node);
            auto left = root->left;
            auto right = root->right;
            root->abandon();
            delete root;

            if(right)
                right->makeOrphan();

            if(left) {
                left->makeOrphan();
                auto bigLeft = mostRight(left);
                splayAndRoot(bigLeft);
                root->right = right;
                if(right)
                    right->parent = root;
            }
            else
                root = right;
            if(root)
                after(root);
            return true;
        }

        Node* findProximity(const key_type& el) {
            return root ? implFindBelow(el, root) : nullptr;
        }

        Node* implFindBelow(const key_type& el, Node* node) {
            if(node->val == el)
                return node;
            if(el < node->val)
                return node->left ? implFindBelow(el, node->left) : node;
            else
                return node->right ? implFindBelow(el, node->right) : node;
        }

        void rightRotation(Node* node) {
            auto p = node;
            auto q = p->parent;

            auto b = p->right;
            auto top = q->parent;

            p->parent = top;
            p->right = q;

            q->parent = p;
            q->left = b;

            if(b)
                b->parent = q;
            if(top)
                top->change(q, p);

            after(q), after(p);
        }

        void leftRotation(Node* node) {
            auto p = node->parent;
            auto q = node;
            auto b  = q->left;
            auto top = p->parent;
            q->parent = top;
            q->left = p;
            p->parent = q;
            p->right = b;

            if(b)
                b->parent = p;
            if(top)
                top->change(p, q);
            after(p), after(q);
        }

        void rotate(Node* node) {
            assert(node);

            if(not node->parent)
                return;

            if(node->parent->whichChild(node))
                leftRotation(node);
            else
                rightRotation(node);
        }
        void splayAndRoot(Node* node) {
            splay(node), root = node;
        }
        void splay(Node* node) {
            assert(node);
            while(node->parent && node->parent->parent) {
                auto parent = node->parent;
                if(parent->whichChild(node) == parent->parent->whichChild(parent))
                    rotate(parent), rotate(node);
                else
                    rotate(node), rotate(node);
            }
            if(node->parent)
                rotate(node);
        }

        Node* mostRight(Node* node) { assert(node); return node->right ? mostRight(node->right) : node; }
        Node* mostLeft(Node* node) { assert(node); return node->left ? mostLeft(node->right) : node; }

        void clear() { delete root; }
        Node* root;
        AfterRotate after;
    };
}
