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
	int determinant1();
    int determinant2();
    int determinant3();
	int cramer();
};

#endif // TEST_HPP
