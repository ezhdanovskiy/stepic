#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include <ctime>
#include <sys/time.h>
#include <assert.h>

#if 1
#define LOG_END "\t\t[" << __FILE__ << ":" << __LINE__ << "]" << std::endl;
#define LOG(chain) std::cout << chain << LOG_END
#define LOG1(el) std::cout << #el << "=" << (el) << LOG_END
#define LOG2(el1, el2) std::cout << #el1 << "=" << (el1) << "\t" << #el2 << "=" << (el2) << LOG_END
#define LOG3(el1, el2, el3) std::cout << #el1 << "=" << (el1) << "\t" << #el2 << "=" << (el2) << "\t" << #el3 << "=" << (el3) << LOG_END
#define LOGA(a) for (int el : a) std::cout << el << " "; std::cout << LOG_END
#define LOG_ADR(el) LOG_ADR_(el) << LOG_END
#define LOG_ADR_(el) std::cout << "&" << #el << "=" << std::hex << &el << std::dec << "=" << (int)&el
#define LOG_MEM(el) LOG_ADR_(el) << "\t"; { unsigned char *p = (unsigned char *) &el; for (int i = 0; i < sizeof(el); ++i) printf("%02x", p[i]); } std::cout << LOG_END
#else
#define LOG(chain)
#define LOG1(el)
#define LOG2(el1, el2)
#define LOG3(el1, el2, el3)
#define LOGA(a)
#define LOG_ADR(el)
#define LOG_MEM(el)
#endif
