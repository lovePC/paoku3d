#ifndef _MAP_SEQUENCE_H_
#define _MAP_SEQUENCE_H_
#include <vector>
struct  SequenceInfo
{
	unsigned short L;//left track
	unsigned short M;//middle track
	unsigned short R;//right track
	SequenceInfo(unsigned short l,unsigned short m,unsigned short r);
};


#define EMPTY 0
#define MONSTER 1
#define COIN 2

class MapSequence{
public:
	MapSequence(const char* sequence_file);
	MapSequence();
	SequenceInfo pump();
	int gettotalSequence();
	void rewind();
	bool isEos();
private:
	void add(unsigned short l,unsigned short m,unsigned short r);
	int index;
	std::vector<SequenceInfo> sequence;
};

#endif _MAP_SEQUENCE_H_