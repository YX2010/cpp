#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include "message.h"

class Folder;
class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	
	//
	// Folder被隐式初始化为空集合
	//
	explicit Message(const std::string &s = ""):
		contents_(s) {}

	// 拷贝控制成员，用来管理指向本Message的指针
	Message(const Message&);						// 拷贝构造函数
	Message& operator=(const Message&);	// 拷贝赋值运算符
	~Message();													// 析构函数

	//
	// 从给定Folder集合中添加/删除本Message
	//
	void save(Folder&);
	void remover(Folder&);

private:
	std::string contents_;			// 实际包含文本
	std::set<Folder*> folders_;	// 包含本Message的Folder

	//
	// 拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	//
	// 将本Message添加到指向参数的Folder中
	void add_to_Folders(const Message&);

	//
	// 当一个Message被销毁时，我们必须从指向此Message的Folder中删除它
	// 拷贝赋值运算符也要执行此操作，因此定义一个公共函数来完成些工作
	// 从folders_ 中的每个Folder中删除本Message
	void remove_from_Folders(const Message&);
};

#endif
