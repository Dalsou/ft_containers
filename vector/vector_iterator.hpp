#include "../shared/random_iterator.hpp"

		// ******************** Iterator class ******************** //

namespace ft {

    template <typename T>
	class iterator : public random_iterator<T> {

        public:
            typedef std::ptrdiff_t          difference_type;
	
		protected:
			typedef random_iterator<T> iter;
			
		private:
			iterator(const random_iterator<T> &src) : random_iterator<T>(src) {}

		public:
			iterator() : random_iterator<T>() {};
            iterator(T* src) : random_iterator<T>(src) {}
			iterator(const iterator &src) : random_iterator<T>(src) {}
			typedef T&			reference;
			typedef T*			pointer;
			reference	operator*() const {
				return *this->_value;
			}
			pointer	operator->() const {
				return this->_value;
			}
			iterator&	operator+=(difference_type n) {
				this->_value += n;
				return *this;
			}
			iterator&	operator-=(difference_type n) {
				this->_value -= n;
				return *this;
			}
			reference	operator[](difference_type n) const {
				return this->_value[n];
			}
			// Increment
			iterator&	operator++() {
				iter::operator++();
				return *this;
			}
			iterator	operator++(int) {
				return iter::operator++(0);
			}
			// Decrement
			iterator&	operator--() {
				iter::operator--();
				return *this; 
			}
			iterator	operator--(int) {
				return iter::operator--(0);
			}
			// Increment by n
			iterator	operator+(difference_type n) const {
				return iter::operator+(n);
			}
			// Decrement by n
			iterator	operator-(difference_type n) const {
				return iter::operator-(n);
			}
			difference_type	operator-(const random_iterator<T> &n) const { 
				return iter::operator-(n);
			}
			friend iterator	operator+(difference_type n, const iterator &it) { 
				return it.operator+(n);
			}
		
	}; // class iterator

	// ******************** Const Iterator class ******************** //
    template <typename T>
	class const_iterator : public random_iterator<T> {

        public:
            typedef std::ptrdiff_t      difference_type;
	
		protected:
			typedef random_iterator<T>  iter;
	
		public:
			const_iterator() : random_iterator<T>() {};
            const_iterator(T *src) : random_iterator<T>(src) {};
			const_iterator(const random_iterator<T> &src) : random_iterator<T>(src) {};
			typedef const T&		reference;
			typedef const T*		pointer;
			reference	operator*() const {
				return *this->_value;
			}
			pointer	operator->() const {
				return this->_value;
			}
			const_iterator&	operator+=(difference_type n) {
				this->_value += n;
				return *this;
			}
			const_iterator&	operator-=(difference_type n) {
				this->_value -= n;
				return *this;
			}
			reference	operator[](difference_type n) const {
				return this->_value[n];
			}
			// Increment				
			const_iterator&	operator++() {
				iter::operator++();
				return *this;
			}
			const_iterator	operator++(int) {
				return iter::operator++(0);
			}
			// Decrement
			const_iterator&	operator--() {
				iter::operator--();
				return *this;
			}
			const_iterator	operator--(int) {
				return iter::operator--(0);
			}
			// Increment by n
			const_iterator	operator+(difference_type n) const {
				return iter::operator+(n);
			}
			// Decrement by n
			const_iterator	operator-(difference_type n) const {
				return iter::operator-(n);
			}
			
			difference_type	operator-(const random_iterator<T> &n) const {
				return iter::operator-(n);
			}
			friend const_iterator	operator+(difference_type n, const const_iterator &it) {
				return it.operator+(n);
			}
	}; // class const_iterator

} // namespace ft