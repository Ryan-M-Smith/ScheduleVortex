//
// FILENAME: tasklist.hpp | Schedule Vortex
// DESCRIPTION: A list of tasks the user needs to do that day
// CREATED: 2023-02-07 @ 11:39 AM
// COPYRIGHT: Copyright (c) 2023 by Ryan Smith <rysmith2113@gmail.com>
//

#ifndef TASK_LIST_HPP
#define TASK_LIST_HPP

#include <string>
#include <vector>

#include <QListWidget>
#include <QString>

#include "qt-ui.hpp"

using std::string;

class TaskList {
public:
	TaskList(QListWidget* taskList);
	~TaskList();

	void AddTask(const string& taskName);

private:
	QListWidget* m_TaskList;
	std::vector<string> m_Tasks;
};

#endif // TASK_LIST_HPP