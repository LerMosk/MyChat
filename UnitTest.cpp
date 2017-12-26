#include "stdafx.h"
#include "iostream"  
#include <string>
#include <vector>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace std;

namespace TestProject
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};
#pragma region Additional test attributes
#pragma endregion 

		[TestMethod]
		int power(int a, int b, int n) {// a^b mod n
			int tmp = a;
			int sum = tmp;
			for (int i = 1; i < b; i++) {
				for (int j = 1; j < a; j++) {
					sum += tmp;
					if (sum >= n) {
						sum -= n;
					}
				}
				tmp = sum;
			}
			return tmp;
		}

		[TestMethod]
		int mul(int a, int b, int n) {// a*b mod n 
			int sum = 0;

			for (int i = 0; i < b; i++) {
				sum += a;

				if (sum >= n) {
					sum -= n;
				}
			}
			return sum;
		}

		/*****************************************************
		p - простое число
		0 < g < p-1
		0 < x < p-1
		m - шифруемое сообщение m < p
		*****************************************************/

		[TestMethod]
		void crypt(int p, int g, int x, string in, vector <pair<int, int> > &mas) {

			int y = power(g, x, p);

			cout << "Открытый ключ (p,g,y) = " << "(" << p << "," << g << "," << y << ")" << endl;
			cout << "Закрытый ключ x = " << x << endl;

			cout << "\nШифруемый текст:" << endl;

			for (unsigned int i = 0; i < size(in); i++) {
				int m = in[i] + 256;
				if (m > 0) {
					cout << (char)m;

					int k = rand() % (p - 2) + 1; // 1 < k < (p-1) 
					int a = power(g, k, p);
					int b = mul(power(y, k, p), m, p);
					mas.push_back(make_pair(a, b));
				}
			}

			cout << endl;
		}

		[TestMethod]
		void decrypt(int p, int x, vector <pair<int, int> > mas, string &out) {

			cout << "\nДешифрованый текст:" << endl;

			unsigned int i = 0;
			while (i < mas.size()) {
				int a = 0;
				int b = 0;
				a = mas[i].first;
				b = mas[i].second;

				if (a != 0 && b != 0) {
					cout << a << " " << b << endl;

					int deM = mul(b, power(a, p - 1 - x, p), p);// m=b*(a^x)^(-1)mod p =b*a^(p-1-x)mod p
					char m = static_cast<char>(deM);
					out.push_back(m);

					i++;
				}
			}

			cout << endl;
		}

		[TestMethod]
		void TestMethod1()
		{
			string message_in, messagge_out;
			vector<pair<int, int> > cypher;

			cout << "Enter your message: " << endl;
			getline(cin, message_in);

			int x = rand() % (593 - 2) + 1;

			crypt(593, 123, x, message_in, cypher);
			decrypt(593, x, cypher, messagge_out);

			String^ str1 = gcnew String(message_in.c_str());
			String^ str2 = gcnew String(messagge_out.c_str());
			Assert::AreEqual(str1, str2, true);
		}
	};
}


