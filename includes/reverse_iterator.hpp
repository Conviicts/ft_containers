#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

#include "iterator_traits.hpp"

namespace ft {
    template <typename Iterator>
	class reverse_iterator {
		public:
			typedef	ft::iterator_traits<Iterator>			it_traits;
			typedef Iterator								iterator_type;
			typedef typename it_traits::value_type			value_type;
			typedef typename it_traits::difference_type		difference_type;
			typedef typename it_traits::pointer				pointer;
			typedef typename it_traits::reference			reference;
			
			reverse_iterator() : _pointer() {};

			explicit reverse_iterator(iterator_type it) : _pointer(it) {};

			reverse_iterator(reverse_iterator const & src) : _pointer(src._pointer) {};

			reverse_iterator&	operator=(reverse_iterator const & src) {
				if (this != &src)
					_pointer = src._pointer;
				return (*this);
			}
			
			template<typename _Iterator>
			reverse_iterator(reverse_iterator<_Iterator> const & x) : _pointer(x.base()) {};
			friend bool	operator!=(reverse_iterator const & lhs, reverse_iterator const & rhs) {
				if (lhs.base() != rhs.base())
					return true;
				return false;
			}
			iterator_type base() const { return this->_pointer; }

			reference	operator*() const;

			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator(this->_pointer - n);
			}

			reverse_iterator&	operator++() {
				this->_pointer--;
				return *this;
			}

			reverse_iterator	operator++(int) {
				reverse_iterator tmp = *this;
				this->_pointer--;
				return tmp;
			}
			
			reverse_iterator&	operator+=(difference_type n) {
				this->_pointer -= n;
				return (*this);
			}
			
			reverse_iterator	operator-(difference_type n) const {
				return (reverse_iterator(this->_pointer + n));
			}

			reverse_iterator&	operator--() {
				this->_pointer++;
				return *this;
			}

			reverse_iterator	operator--(int) {
				reverse_iterator tmp = *this;
				this->_pointer++;
				return tmp;
			}

			reverse_iterator&	operator-=(difference_type n) {
				this->_pointer += n;
				return (*this);
			}

			pointer	operator->() const {
				return &(operator*());
			}
			
			reference	operator[] ( difference_type n) const {
				return (*(*this + n));
			}

		private:
			Iterator	_pointer;
	};

	template <typename Iterator>
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*() const {
		Iterator tmp = _pointer;
		return *--tmp;
	}

	template<typename Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> & rhs) {
		return (reverse_iterator<Iterator>(rhs.base() - n));
	}
	
	template <typename IteratorL, typename IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL> & lhs,
		const reverse_iterator<IteratorR> & rhs) {
		return rhs.base() - lhs.base();
	}
	
	template <typename Iterator>
	bool operator==(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator> & rhs) {
		if (lhs.base() == rhs.base())
			return true;
		return false;
	}

	template <typename Iterator>
	bool operator!=(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator> & rhs) {
		if (lhs.base() != rhs.base())
			return true;
		return false;
	}


	template <typename Iterator>
	bool operator<(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator> & rhs) {
		return rhs.base() < lhs.base();
	}

	template <typename Iterator>
	bool operator<=(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator> & rhs) {
		if (lhs.base() == rhs.base())
			return true;
		else if (lhs.base() < rhs.base())
			return false;
		return true;
	}

	template <typename Iterator>
	bool operator>(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator> & rhs) {
		return rhs < lhs;
	}

	template <typename Iterator>
	bool operator>=(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator> & rhs) {
		if (lhs.base() == rhs.base())
			return true;
		else if (lhs.base() > rhs.base())
			return false;
		return true;
	}

	template <typename IteratorL, typename IteratorR>
	bool operator==(const reverse_iterator<IteratorL> & lhs,
		const reverse_iterator<IteratorR> & rhs) {
		if (lhs.base() == rhs.base())
			return true;
		return false;
	}

	template <typename IteratorL, typename IteratorR>
	bool operator!=(const reverse_iterator<IteratorL> & lhs,
		const reverse_iterator<IteratorR> & rhs) {
		if (lhs.base() != rhs.base())
			return true;
		return false;
	}

template <typename IteratorR, typename IteratorL>
	bool operator<(const reverse_iterator<IteratorR> & lhs,
		const reverse_iterator<IteratorL> & rhs) {
		return rhs.base() < lhs.base();
	}

	template <typename IteratorR, typename IteratorL>
	bool operator<=(const reverse_iterator<IteratorR> & lhs,
		const reverse_iterator<IteratorL> & rhs) {
		if (lhs.base() == rhs.base())
			return true;
		else if (lhs.base() < rhs.base())
			return false;
		return true;
	}

	template <typename IteratorR, typename IteratorL>
	bool operator>(const reverse_iterator<IteratorR> & lhs,
		const reverse_iterator<IteratorL> & rhs) {
		return rhs < lhs;
	}

	template <typename IteratorR, typename IteratorL>
	bool operator>=(const reverse_iterator<IteratorR> & lhs,
		const reverse_iterator<IteratorL> & rhs) {
		if (lhs.base() == rhs.base())
			return true;
		else if (lhs.base() > rhs.base())
			return false;
		return true;
	}
}

#endif