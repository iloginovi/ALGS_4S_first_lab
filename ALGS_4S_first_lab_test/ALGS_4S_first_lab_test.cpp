#include "pch.h"
#include "CppUnitTest.h"
#include "../ALGS_4S_first_lab/main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ALGS4Sfirstlabtest
{
	TEST_CLASS(ALGS4Sfirstlabtest)
	{
	public:
		
		TEST_METHOD(INSERT_AND_FIND_TEST)
		{
			Map<char, int> Map;
			Map.Insert('T', 12);
			Map.Insert('U', 95);
			Map.Insert('K', 76);
			int k1, k2, k3;
			k1 = Map.Find('T');
			k2 = Map.Find('U');
			k3 = Map.Find('K');
			Assert::AreEqual(k1, 12);
			Assert::AreEqual(k2, 95);
			Assert::AreEqual(k3, 76);
		}
		TEST_METHOD(DELETE_TEST)
		{
			Map<char, int> Map;
			Map.Insert('T', 12);
			Map.Insert('U', 95);
			Map.Insert('B', 1);
			Map.Insert('K', 76);
			Map.Delete('B');
			auto itr = Map.create_iterator();
			while (itr->has_next())
			{
				Pair<char, int> pair = itr->next();
				Assert::IsTrue(pair.first!='B');
				Assert::IsTrue(pair.second != 1);
			}
		}
		TEST_METHOD(GET_KEYS_TEST){
			Map<char, int> Map;
			Map.Insert('T', 12);
			Map.Insert('U', 95);
			Map.Insert('K', 76);
			List<char> KEYS;
			Map.Get_Keys(&KEYS);
			Assert::IsTrue((KEYS.head->value=='T')|| (KEYS.head->value == 'U') || (KEYS.head->value == 'K'));
			Assert::IsTrue((KEYS.head->next->value == 'T') || (KEYS.head->next->value == 'U') || (KEYS.head->next->value == 'K'));
			Assert::IsTrue((KEYS.head->next->next->value == 'T') || (KEYS.head->next->next->value == 'U') || (KEYS.head->next->next->value == 'K'));
		
		}
		TEST_METHOD(GET_VALUES_TEST)
		{
			Map<char, int> Map;
			Map.Insert('T', 12);
			Map.Insert('U', 95);
			Map.Insert('K', 76);
			List<int> VALUES;
			Map.Get_Values(&VALUES);
			Assert::IsTrue((VALUES.head->value == 12) || (VALUES.head->value == 95) || (VALUES.head->value == 76));
			Assert::IsTrue((VALUES.head->next->value == 12) || (VALUES.head->next->value == 95) || (VALUES.head->next->value == 76));
			Assert::IsTrue((VALUES.head->next->next->value == 12) || (VALUES.head->next->next->value == 95) || (VALUES.head->next->next->value == 76));
		}
	};
}
