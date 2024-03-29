//
// FILENAME: listwrapper.hpp | Schedule Vortex
// DESCRIPTION: A list of tasks the user needs to do that day
// CREATED: 2023-02-07 @ 11:39 AM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#ifndef LIST_WRAPPER_HPP
#define LIST_WRAPPER_HPP

#include <string>
#include <vector>

#include <QListWidget>
#include <QString>

#include "qt-ui.hpp"

using std::string;

class ListWrapper {

public:
	ListWrapper(QListWidget* listWidget);
	~ListWrapper();

	void AddItem(const string& itemName);
	void DeleteItem(unsigned int index);
	void Clear();

private:
	QListWidget* m_ListWidget;
	std::vector<string> m_Items;
};

#endif // LIST_WRAPPER_HPP