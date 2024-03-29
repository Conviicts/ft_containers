#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "vector.hpp"

namespace ft {
	template < class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit stack(const container_type & ctnr = container_type()) : _stack(ctnr) {};

			bool				empty() const { return _stack.empty(); }
			size_type			size() const { return _stack.size(); }
			value_type			&top() { return _stack.back(); }
			const value_type	&top() const { return _stack.back(); }
			void				push(const value_type & val ) { _stack.push_back(val); }
			void				pop() { _stack.pop_back(); }
			
			template<class _T, class _Container>
			friend bool	operator==(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs);

			template<class _T, class _Container>
			friend bool	operator!=(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs);
			
			template<class _T, class _Container>
			friend bool	operator<(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs);
			
			template<class _T, class _Container>
			friend bool	operator<=(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs);
			
			template<class _T, class _Container>
			friend bool	operator>(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs);
			
			template<class _T, class _Container>
			friend bool	operator>=(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs);
		private:
			container_type _stack;
	};
	
	template<class _T, class _Container>
	bool	operator==(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs) {
		return (lhs._stack == rhs._stack);
	}

	template<class _T, class _Container>
	bool	operator!=(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs) {
		return (lhs._stack != rhs._stack);
	}
	
	template<class _T, class _Container>
	bool	operator<(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs) {
		return (lhs._stack < rhs._stack);
	}	
	
	template<class _T, class _Container>
	bool	operator<=(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs) {
		return (lhs._stack <= rhs._stack);
	}
	
	template<class _T, class _Container>
	bool	operator>(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs) {
		return (lhs._stack > rhs._stack);
	}
	
	template<class _T, class _Container>
	bool	operator>=(stack<_T, _Container> const & lhs, stack<_T, _Container> const & rhs) {
		return (lhs._stack >= rhs._stack);
	}
}

#endif