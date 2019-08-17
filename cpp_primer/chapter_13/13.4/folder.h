#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include "message.h"
class Message;
class Folder{
	friend Message;
	friend swap(Folder&, Folder&);
public:
	Folder() = default;

	Folder(const Folder&);
	Message& operator=(const Folder&);
	~Folder();

	//
	// 添加/删除给定Message 至本 Folder
	void addMeg(const Message*);
	void remMeg(const Message*);

private:
	std::set<Message&> messages_;				// 本Folder所包含的Messages
	//
	// 拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	// 将本Folder添加至指向参数的Message中
	void add_to_Message(const Folder&);	
	void remove_from_Message();

};

#endif
