#include <iostream>
#include <vector>
#include <string>

class book {
	public:
		inline book() : received_book_cnt(3) {}
		book(std::vector<std::string> &);
		int get_received_book_cnt();
	private:
		std::vector<std::string> book_sn;
		int received_book_cnt;
};

book::book(std::vector<std::string> &exist_books) {

	book_sn = exist_books;
}

int book::get_received_book_cnt() {

	return received_book_cnt;
}

int main()
{
	book myBook;

	std::cout << myBook.get_received_book_cnt() << std::endl;

	return 1;
}
