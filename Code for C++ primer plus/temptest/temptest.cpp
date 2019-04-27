
#include "pch.h"
#include <iostream>





class Screen
{
public:
	//Screen();
	~Screen();
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){}
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

//Screen::Screen()
//{
//}

Screen::~Screen()
{
	std::cout << "bye bye~";
}

inline
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

//void main()
//{
//	Screen s1(3, 6, 'g'),s2(10,20,'a');
//	std::cout<<"s1.get() "<<s1.get()<<"\n";
//	Screen *p = new Screen();
//	system("pause");
//	std::cout << "p.get(1, 2) " << p->get() << "\n";
//}