#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "queue.h"

enum Borders
{
	min_k = 1, 
	min_tacts = 1, 
	min_queueSize = 5,
	max_k = 64, 
	max_tacts = 1000, 
	max_queueSize = 50, 
	max_dur = 10 
};

struct Statistics
{
	int total_tasks = 0;
	int failures = 0;
	int completed_tasks = 0; 
	int lost_tasks_in_queue = 0; 
	int tasks_in_progress = 0; 
	int idle_cycles_of_cluster = 0; 
	double average_cluster_load = 0.0; 

	friend std::ostream& operator<< (std::ostream& out, const Statistics& st); 
};

struct Task
{
	int id; 
	int time;  
	int dur; 
	int proc;

	Task(int _id, int _k) : id(_id) 
	{
		time = 0; 
		dur = rand() % Borders::max_dur + 1;
		proc = rand() % _k + 1;
	}
};

class Cluster
{
private:
	int k; 
	int tacts; 
	int queueSize; 
	double frequency; 

public:
	Cluster(int _k, int _tacts, int _queueSize, double _frequency); 

	Statistics simulation(); 
};
