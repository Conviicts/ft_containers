#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
#include <iterator>
#include <new>
#include <exception>
#include <memory>
#include <iterator>

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft {
    template<class T, class Alloc = std::allocator<T> >
	class vector {
		public:
		
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef size_t													size_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef T*														iterator;
			typedef const T*												const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;

			explicit vector(const allocator_type& alloc = allocator_type()) {
				_allocator = alloc;
				_n = 0;
				_capacity = 0;
				_start = NULL;
				_end = NULL;
			}

			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) {

				_allocator = alloc;
				_start = NULL;
				if (n > _allocator.max_size())
					throw std::out_of_range("out of range");
				if (n) {
					_start = _allocator.allocate(n);
					_capacity = n;
				}
				else
					_capacity = 0;
				_n = n;
				_end = _start + _n;
				iterator pos = _start;
				for (size_type i = 0; i < n; i++)
					_allocator.construct(pos++, val);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			
					_allocator = alloc;
					difference_type dist = std::distance(first, last);
					_n = static_cast<size_type>(dist);
					_capacity = static_cast<size_type>(dist);
					if (dist) {    
						if (_capacity > _allocator.max_size())
							throw std::out_of_range("out of range");
						_start = _allocator.allocate(_capacity);
						std::uninitialized_copy(first, last, _start);
					}
					_end = _start + _n;
			}

			vector(const vector& src) {
				_start = NULL;
				_n = src._n;
				_capacity = src._capacity;
				if (src._capacity)
					_start = _allocator.allocate(_capacity);
				if (src._capacity)
					std::uninitialized_copy(src._start, src._start + src._n, _start);
				_end = _start + _n;
			}

			virtual ~vector() {
				clear();
				if (_capacity)
					_allocator.deallocate(_start, _capacity);
			}

			vector	&operator=(const vector& rhs) {

				if (*this != rhs) {
					_dealloc();
					if (rhs.empty())
						return (*this);
					_n = rhs.size();
					_capacity = rhs.capacity();
					if (capacity() > _allocator.max_size())
						throw std::out_of_range("out of range");
					_start = _allocator.allocate(rhs.capacity());
					_capacity = rhs.capacity();
					std::uninitialized_copy(rhs.begin(), rhs.end(), _start);
					_end = _start + _n;
				}
				return (*this);
			}

			iterator	begin() {
				iterator res = _start;
				return	res;
			}

			const_iterator begin() const {
				const_iterator res = _start;
				return res;
			}
			
			reverse_iterator	rbegin(void) {
				return (reverse_iterator(_end));
			}
			
			const_reverse_iterator	rbegin(void) const {
				return (const_reverse_iterator(_end));
			}
			
			reverse_iterator	rend(void) {
				return (reverse_iterator(_start));
			}

			const_reverse_iterator	rend(void) const {
				return (const_reverse_iterator(_start));
			}
			
			iterator	end() {
				iterator res = _end;
				return res;
			}
			
			const_iterator end() const {
				const_iterator res = _end;
				return res;
			}

			size_type	size() const { return _n; }
			size_type	max_size() const { return _allocator.max_size(); }
			
			void resize(size_type size, value_type val = value_type()) {
				if (size > _allocator.max_size())
					throw std::out_of_range("error");
			    if (size == _n)
			        return ;
			    if (size == 0)
			        return (clear());
			    if (size < _n) {
			        iterator it = end();
			        size_type diff = _n - size;
			        while (diff--) {
			            _allocator.destroy(--it);
			            _n--;
			        }
					_end = _start + _n;
			        return ;
			    }
			    if (size > _n)
			        _reallocc(size, val);
			}
			
			size_type	capacity() const { return _capacity; }
			
			bool		empty() const {
				if (_n == 0)
					return true;
				return false;
			}

			void	reserve(size_type n) {
				if (_capacity > n)
					return ;
				if (n > max_size())
					throw std::out_of_range("vector::reserve out of range");
				else
					_realloc(n);
			}
			
			reference		operator[](size_type n) { return (_start[n]); }
			
			const_reference	operator[](size_type n) const { return (_start[n]); }
			
			reference		at(size_type n) {
				if (n > _n)
					throw std::out_of_range("Error: out of range");
				return (_start[n]);
			}
			
			const_reference	at(size_type n) const {
				if (n > _n)
					throw std::out_of_range("Error: out of range");
				return (_start[n]);
			}
			
			reference		front() {return *(_start);}
			
			const_reference	front() const { return *(_start);}
			
			reference		back() { return *(_start + (_n - 1)); }
			
			const_reference	back() const { return *(_start + (_n - 1)); }
			

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
				size_type i = std::distance(first, last);
				_dealloc();
				if (i) {
					if (i > max_size())
						throw std::out_of_range("vector::reserve out of range");
					_start = _allocator.allocate(i);
					_capacity = i;
				}
				for (iterator tmp = begin(); tmp < begin() + i ; tmp++)
					_allocator.construct(tmp, *first++);
				_n = i;
				_end = _start + _n;
			}
			
			void	assign(size_type n, const value_type& val) {
				_dealloc();
				if (n)
					reserve(n);
				for (iterator tmp = begin(); tmp < begin() + n; tmp++)
					_allocator.construct(tmp, val);
				_n = n;
				_end = _start + _n;
			}

			void	push_back(const value_type & val) {
				if (_capacity <= _n)
					reserve(_capacity + 6);
				_allocator.construct(_end, val);
				_end++;
				_n++;
			}
			
			void	pop_back() {
				if (_n > 0) {
					_allocator.destroy(_end - 1);
					_end--;
					_n--;
				}
			}

			iterator insert(iterator position, const value_type & val) {
				difference_type res = std::distance(begin(), position);
				insert(position, 1, val);
				return _start + res;
			}
			
			void	insert(iterator position, size_type n, const value_type& val) {
				difference_type			beginToPos = std::distance(begin(), position);
				difference_type			prevSize = _n;
				iterator				prev;
				iterator				end;

				resize(_n + n);
				prev = begin() + prevSize;
				position = begin() + beginToPos;
				end = _start + _n;
				while (prev != position) {
					*(--end) = *(--prev);
				}
				while (0 < n) {
					*position++ = val;
					n--;
				}
				_end = _start + _n;
			}

			template <class InputIterator>
				void	insert (iterator position, InputIterator first, InputIterator last, 
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
					size_type	pos = 0;
					for (iterator tmp = begin(); tmp != position; tmp++) {
						pos++;
						if (tmp == end())
							return ;
					}
					size_type d = std::distance(first, last);
					difference_type p = std::distance(begin(), end());
					resize(_n + d);
					iterator end = _start + (p - 1);
					iterator endd = _end - 1;
					iterator res = begin();
					size_type e = _n;
					while (e > (pos + d)) {
						*endd = *end;
						end--;
						endd--;
						e--;
					}
					for (size_type i = 0; i < pos; i++)
						res++;
					for (size_type t = 0; t < d; t++) {
						*res = *first;
						res++;
						first++;
					}
				}
			
			iterator erase(iterator position) {
				if (position == end())
					return position;
				return (erase(position, position + 1));
			}

			iterator	erase(iterator first, iterator last) {
				if (first == last)
					return (first);
				if (last == end()) {
					for (iterator i = first; i != last; i++) {
						_allocator.destroy(i);
						_n--;
						_end--;
					}
					return (first);
				}
				iterator it = first;
				difference_type size = std::distance(first, last);
				while (it != last) {
					_allocator.destroy(it);
					it++;
				}
				it = first;
				while (it + size != end()) {
					_allocator.construct(it, *(it + size));
					_allocator.destroy(it + size);
					it++;
				}
				_n -= static_cast<size_type>(size);
				_end = _start + _n;
				return (first);
			}

			void	swap(vector & x) {
				std::swap(_allocator, x._allocator);
				std::swap(_n, x._n);
				std::swap(_capacity, x._capacity);
				std::swap(_start, x._start);
				std::swap(_end, x._end);
			}
			
			void	clear()
			{
				if (_n == 0)
					return;
				size_type len = size();

				for (size_type i = 0; i < len; i++)
				{
					_end--;
					_allocator.destroy(_end);
				}
				_n = 0;
			}
			allocator_type get_allocatorator() const { return _allocator; }
		private:
			allocator_type	_allocator;
			size_type		_n;
			size_type		_capacity;
			pointer			_start;
			pointer			_end;

            void _dealloc() {
				if (_capacity)
			    {
			        for (size_type i = 0; i < _n; i++)
			            _allocator.destroy(_start + i);
			        _allocator.deallocate(_start, _capacity);
			    }
			    _capacity = 0;
			    _n = 0;
				_end = NULL;
				_start = NULL;
			}

            void	_realloc(size_type n) {
				size_type	prevSize = _n;
				iterator	tmp = _allocator.allocate(n);
				std::uninitialized_copy(_start, _start + _n, tmp);
				_dealloc();
				_n = prevSize;
				_start = tmp;
				_capacity = n;
				_end = _start + _n;
			}

			void _reallocc(size_type new_size, value_type const & value) {
			    iterator temp = _allocator.allocate(new_size);
			    size_type old_size(_n);
			    std::uninitialized_copy(_start, _start + _n, temp);
			    _dealloc();
			    _start = temp;
			    std::uninitialized_fill(_start + old_size, _start + new_size, value);
			    _n = new_size;
				_end = _start + _n;
			    _capacity = new_size;
			}
	};

    template <class T, class Alloc>
    bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
        if (lhs.size() == rhs.size())
        {
            typename vector<T>::const_iterator l = lhs.begin();
            typename vector<T>::const_iterator r = rhs.begin();
            while(l != lhs.end() && r != rhs.end())
            {
                if (*l != *r)
                    return (false);
                l++;
                r++;
            }
            return true;
        }
        return false;
    }
	
	template <class T, class Alloc>
    bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
        return (!(lhs == rhs));
    }

	template <class T, class Alloc>
    bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
        if (lhs != rhs)
            return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        return false;
    }
	
	template <class T, class Alloc>
    bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
        if (lhs == rhs)
            return true;
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
	
	template <class T, class Alloc>
    bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
        if (lhs != rhs)
            return (!(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
        return false;
    }

	template <class T, class Alloc>
    bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
        if (lhs == rhs)
            return true;
        return (!(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
    }

	template <class T, class Alloc>
    void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
        x.swap(y);
    }
}

#endif