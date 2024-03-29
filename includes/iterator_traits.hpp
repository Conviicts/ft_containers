#ifndef __ITERATOR_TRAITS_HPP__
#define __ITERATOR_TRAITS_HPP__

namespace ft {
    struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag{};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <typename Category, typename T, typename Distance = std::ptrdiff_t,
	    typename Pointer = T*, typename Reference = T&>
	struct iterator {
	    typedef T         value_type;
	    typedef Distance  difference_type;
	    typedef Pointer   pointer;
	    typedef Reference reference;
	    typedef Category  iterator_category;
	};
	
	template <typename Iterator>
	struct iterator_traits {
        typedef typename Iterator::difference_type	difference_type;
        typedef typename Iterator::value_type		value_type;
        typedef typename Iterator::pointer			pointer;
        typedef typename Iterator::reference		reference;
	};

	template <typename T>
	struct iterator_traits<T*> {
        typedef random_access_iterator_tag	iterator_category;
        typedef std::ptrdiff_t				difference_type;
        typedef T							value_type;
        typedef T*							pointer;
        typedef T&							reference;
	};

	template <typename T>
	struct iterator_traits<const T*> {
        typedef random_access_iterator_tag	iterator_category;
        typedef std::ptrdiff_t				difference_type;
        typedef T							value_type;
        typedef const T*					pointer;
        typedef const T&					reference;
	};
}

#endif