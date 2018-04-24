#ifndef TEST_HPP
#define TEST_HPP
#define NDEBUG


class Test
{
public:
	Test();
	~Test();
	void chooseTest();

private:
    void menu();
	void emptyMatrix();
	void operators1();
	void determinant();
	void cramer();
};

#endif // TEST_HPP
