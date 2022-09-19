#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft {
    template<typename T, typename node_type>
    class RBTIterator {
        public:
            typedef T								value_type;
            typedef T*								pointer;
            typedef T&								reference;
            typedef const T&						const_reference;
            typedef const T*						const_pointer;
            typedef	ft::bidirectional_iterator_tag	iterator_categorie;
            typedef ptrdiff_t						difference_type;
            typedef node_type*						node_pointer;

            node_pointer	_node;

            RBTIterator() : _node() {}

            RBTIterator(node_pointer src) : _node(src) {}

            RBTIterator(RBTIterator const & src) : _node(src._node) {}

            RBTIterator&	operator=(RBTIterator const & src) {
                if (this != &src)
                    this->_node = src._node;
                return *this;
            }

            operator	RBTIterator<value_type const, node_type const>() const {
                return RBTIterator<value_type const, node_type const>(_node);
            }

            reference operator*() {
                return *_node->data;
            }

            pointer	operator->() {
                return _node->data;
            }

            const_reference operator*() const {
                return *_node->data;
            }

            const_pointer	operator->() const {
                return _node->data;
            }

            RBTIterator&	operator++() {
                increment();
                return *this;
            }
            
            RBTIterator operator++(int) {
                RBTIterator tmp(*this);
                increment();
                return tmp;
            }
            
            RBTIterator& operator--() {
                decrement();
                return *this;
            }
            
            RBTIterator operator--(int) {
                RBTIterator tmp(*this);
                decrement();
                return tmp;
            }
            
            bool	operator==(RBTIterator const & val) const {
                return _node == val._node;
            }
            
            bool	operator!=(RBTIterator const & val) const {
                return _node != val._node;
            }

        protected:
            void	increment() {
                if (_node == _node->nil_node)
                    return ;
                if (_node->right != _node->nil_node) {
                    _node = _min(_node->right);
                    return;
                }
                else {
                    node_pointer tmp = _node->parent;
                    while (tmp != _node->nil_node && tmp != 0 && _node == tmp->right) {
                        _node = tmp;
                        tmp = tmp->parent;
                    }
                    if (tmp == 0)
                        _node = _node->nil_node;
                    else
                        _node = tmp;
                }
            }
            void	decrement() {
                if (_node == _node->nil_node) {
                    _node = _node->nil_node->max;
                    return ;
                }
                if (_node->left != _node->nil_node) {
                    _node = _max(_node->left);
                    return;
                }
                else {
                    node_pointer tmp = _node->parent;
                    while(tmp != _node->nil_node && tmp != 0 && _node == tmp->left) {
                        _node = tmp;
                        tmp = tmp->parent;
                    }
                    if (tmp == 0)
                        _node = _node->nil_node;
                    else
                        _node = tmp;
                }
            }
        private:
            node_pointer	_min(node_pointer node) const {
                while (node->left != node->nil_node)
                    node = node->left;
                return node;
            }
            node_pointer	_max(node_pointer node) const {
                while (node->right != node->nil_node)
                    node = node->right;
                return node;
            }
    };
};
#endif
