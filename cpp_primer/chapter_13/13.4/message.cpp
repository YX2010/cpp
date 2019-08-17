#include "message.h"
#include "folder.h"

void Message::save(Folder &f){
	folders_.insert(f);	// 将给定的Folder添加至我们的Folder列表(folders_)
	f.insert(this);			// 将本Message添加至f的Message集合中
}

void Message::remove(Folder &f){
	folders_.erase(f);
	f.remMsg(this);
}

//
// 将本Message添加至m的Folder中
//
void add_to_Folders(const Message &m){
	for(auto f : m.folders_){
		f->addMsg(this);
	}
}

//
// Message 的拷贝构造函数
//
Message::Message(const Message &m)
	contents_(m.contents_), folders_(m.folders_){
		add_to_Folders(m);	// 将本消息添加至指向m的Folder中
}

//
// 当一个Message被销毁时，我们必须从指向此Message的Folder中删除它
// 拷贝赋值运算符也要执行此操作，因此定义一个公共函数来完成些工作
// 从对应的Folder中删除本Message
//
void Message::remove_from_Folders(){
	for(auto f : folders_){	// 对Folder中每一个指针
		f->remMsg(this);				// 从该Folder中删除本Messsage
	}
}

Message::~Message(){
	remove_from_Folders();
}

//
//
Message& Message::operator=(const Message &rhs){
	// 通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders();		// 更新已有Folder
	contents_ = rhs.contents_;// 从rhs拷贝消息内容
	folders_ = rhs.folders_;	
	add_to_Folders(rhs);			// 将本Message添加到那些Folder中
	return *this;
}

// 
// 通过两遍扫描folders_中每个成员来正确处理Folder指针。
// 每一遍扫描将Message从它们所在的Folder中删除。接下来
// 我们调用swap来交换数据成员。最后再对folders_进行每二遍
// 扫描来添加交换过的Message
//
void swap(Message &lhs, Message &rhs){
	// 在本例中严格来说并不需要，但这是一个好习惯
	using std::swap;
	//
	// 将每个消息的指针从它（原来）所在Folder中删除
	for (auto f : lhs.folders_){
		f->remMsg(&lhs);
	}

	for (auto f : rhs.folders_){
		f->remMsg(&rhs);
	}

	//
	// 交换contents_和Folder指针set
	swap(lhs.folders_, rhs.folders_);		// 使用swap(set&, set&)
	swap(lhs.contents_, rhs.contents_);	// swap(string&, string&)

	//
	// 将每个Message的指针添加至它的（新）Folder中
	for (auto f : lhs.folders_){
		f->addMsg(lhs);
	}
	for (auto f : rhs.folders_){
		f->addMsg(rhs);
	}
}
