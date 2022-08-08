#pragma once
class String
{
private:
	char* str;
	int checkPos(int pos, int s)
	{
		if (pos > s)
		{
			return s;
		}
		return pos;
	}
	int checkCount(int pos, int count, int s)
	{
		if (pos + count > s)
		{
			return s - pos;
		}
		return count;
	}
public:
	String()
	{

	}
	String(char* str)
	{
		this->str = str;
	}
	//~String()
	//{
	//	delete[]str;
	//}
	void print()
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	int size()
	{
		int size = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}
	int length()
	{
		int size = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}
	void resize(int n)
	{
		int s = size();
		n = checkPos(n, s);
		char* buf = new char[n+1];
		for (int i = 0; i<n; i++)
		{
			buf[i] = str[i];
		}
		buf[n] = '\0';
		delete[]str;
		str = buf;
	}
	void resize(int n, char c)
	{
		int s = size();
		char* buf = new char[n+1];
		for (int i = 0; i < n && str[i] != '\0'; i++)
		{
			buf[i] = str[i];
		}
		for (int i = s; i < n; i++)
		{
			buf[i] = c;
		}
		buf[n] = '\0';
		delete[]str;
		str = buf;
	}
	void clear()
	{
		char* buf = new char[1]{""};
		delete[]str;
		str = buf;
	}
	bool empty()
	{
		if (size() == 0) return true;
		else return false;
	}
	void push_back(char c)
	{
		int s = size();
		char* buf = new char[s+2];
		for (int i = 0; str[i] != '\0'; i++)
		{
			buf[i] = str[i];
		}
		buf[s] = c;
		buf[s+1] = '\0';
		delete[]str;
		str = buf;
	}
	void append(int n, char c)
	{
		int s = size();
		char* buf = new char[s+n];
		for (int i = 0; str[i] != '\0'; i++)
		{
			buf[i] = str[i];
		}
		for (int i = s; i < n; i++)
		{
			buf[i] = c;
		}
		buf[s + n - 1] = '\0';
		delete[]str;
		str = buf;
	}
	void append(String str2)
	{
		int s = size();
		int s2 = str2.size();
		char* buf = new char[s + s2+1];
		for (int i = 0; str[i] != '\0'; i++)
		{
			buf[i] = str[i];
		}
		for (int i = s, k=0; str2.str[k] != '\0'; i++)
		{
			buf[i] = str2.str[k++];
		}
		buf[s + s2] = '\0';
		delete[]str;
		str = buf;
	}
	void append(String str2, int pos, int count)
	{
		int s = size();
		pos = checkPos(pos, s);
		int s2 = str2.size();
		count = checkCount(pos, count, s2);
		char* buf = new char[s + count + 1];
		for (int i = 0; str[i] != '\0'; i++)
		{
			buf[i] = str[i];
		}
		for (int i=0, k = pos, n= s; i<count; i++)
		{
			buf[n++] = str2.str[k++];
		}
		buf[s + count] = '\0';
		delete[]str;
		str = buf;
	}
	void erase(int pos)
	{
		int s = size();
		pos = checkPos(pos, s);
		char* buf = new char[pos+1];
		for (int i = 0; i < pos && str[i] != '\0'; i++)
		{
			buf[i] = str[i];
		}
		buf[pos] = '\0';
		delete[]str;
		str = buf;
	}
	void erase(int pos, int count)
	{
		int s = size();
		pos = checkPos(pos, s);
		count = checkCount(pos, count, s);
		char* buf = new char[s-count+1];
		for (int i = 0; i < pos; i++)
		{
			buf[i] = str[i];
		}
		for (int i = pos + count, k=pos; str[i] != '\0'; i++)
		{
			buf[k++] = str[i];
		}
		buf[s - count] = '\0';
		delete[]str;
		str = buf;
	}
	void insert(int pos, int n, char c)
	{
		int s = size();
		pos = checkPos(pos, s);
		char* buf = new char[s + n + 1];
		for (int i = 0; i < pos && str[i] != '\0'; i++)
		{
			buf[i] = str[i];
		}
		for (int i=0, k = pos; i < n; i++)
		{
			buf[k++] = c;
		}
		for (int i = pos, k = pos+n; str[i] != '\0'; i++)
		{
			buf[k++] = str[i];
		}
		buf[s + n] = '\0';
		delete[]str;
		str = buf;
	}
	void insert(int pos, String str2)
	{
		int s = size();
		pos = checkPos(pos, s);
		int s2 = str2.size();
		char* buf = new char[s + s2 + 1];
		for (int i = 0; i<pos; i++)
		{
			buf[i] = str[i];
		}
		for (int i = pos, k = 0; str2.str[k] != '\0'; i++)
		{
			buf[i] = str2.str[k++];
		}
		for (int i = pos+s2, k = pos; str[k] != '\0'; i++)
		{
			buf[i] = str[k++];
		}
		buf[s + s2] = '\0';
		delete[]str;
		str = buf;
	}
	void insert(int pos, String str2, int posStr2, int count)
	{
		int s = size();
		pos = checkPos(pos, s);
		int s2 = str2.size();
		posStr2 = checkPos(posStr2, s2);
		count = checkCount(posStr2, count, s2);
		char* buf = new char[s + count + 1];
		for (int i = 0; i < pos; i++)
		{
			buf[i] = str[i];
		}
		for (int i = 0, k = posStr2, n=pos; i<count; i++)
		{
			buf[n++] = str2.str[k++];
		}
		for (int i = pos + count, k = pos; str[k] != '\0'; i++)
		{
			buf[i] = str[k++];
		}
		buf[s + count] = '\0';
		delete[]str;
		str = buf;
	}
	String substr(int pos)
	{
		int s = size();
		pos = checkPos(pos, s);
		char* buf = new char[s - pos+1];
		for (int i = pos, k=0; str[i] != '\0'; i++)
		{
			buf[k++] = str[i];
		}
		buf[s - pos] = '\0';
		return buf;
	}
	String substr(int pos, int count)
	{
		int s = size();
		pos = checkPos(pos, s);
		count = checkCount(pos, count, s);
		char* buf = new char[count+1];
		for (int i = pos, k = 0; k<count; i++)
		{
			buf[k++] = str[i];
		}
		buf[count] = '\0';
		return buf;
	}
	void replace(int pos, int count, int n, char c)
	{
		int s = size();
		pos = checkPos(pos, s);
		count = checkCount(pos, count, s);
		char* buf = new char[s-count+n+1];
		for (int i = 0; i < pos; i++)
		{
			buf[i] = str[i];
		}
		for (int i = 0, k=pos; i < n; i++)
		{
			buf[k++] = c;
		}
		for (int i = pos + count, k=pos+n; str[i] != '\0'; i++)
		{
			buf[k++] = str[i];
		}
		buf[s-count+n] = '\0';
		delete[]str;
		str = buf;
	}
	void replace(int pos, int count, String str2)
	{
		int s = size();
		pos = checkPos(pos, s);
		count = checkCount(pos, count, s);
		int s2 = str2.size();
		char* buf = new char[s-count+s2+1];
		for (int i = 0; i < pos; i++)
		{
			buf[i] = str[i];
		}
		for (int i = 0, k = pos; str2.str[i] != '\0'; i++)
		{
			buf[k++] = str2.str[i];
		}
		for (int i = pos + count, k = pos + s2; str[i] != '\0'; i++)
		{
			buf[k++] = str[i];
		}
		buf[s - count + s2] = '\0';
		delete[]str;
		str = buf;
	}
	void replace(int pos, int count, String str2, int pos2, int count2)
	{
		int s = size();
		pos = checkPos(pos, s);
		count = checkCount(pos, count, s);
		int s2 = str2.size();
		pos2 = checkPos(pos2, s2);
		count2 = checkCount(pos2, count2, s2);
		char* buf = new char[s - count + count2 + 1];
		for (int i = 0; i < pos; i++)
		{
			buf[i] = str[i];
		}
		for (int i = 0, k = pos, n = pos2; i < count2; i++)
		{
			buf[k++] = str2.str[n++];
		}
		for (int i = pos + count, k = pos+count2; str[i] != '\0'; i++)
		{
			buf[k++] = str[i];
		}
		buf[s - count + count2] = '\0';
		delete[]str;
		str = buf;
	}
	int find(String str2, int pos=0)
	{
		int s = size();
		int s2 = str2.size();
		bool flag;
		for (int i = pos; i < s; i++)
		{
			if (str[i] == str2.str[0])
			{
				flag = true;
				for (int j = 1; j < s2; j++)
				{
					if (str[i + j] != str2.str[j])
					{
						flag = false;
						break;
					}
				}
				if (flag) return i;
			}
		}
		return -1;
	}
	int find(String str2, int pos, int n)
	{
		int s = size();
		int s2 = str2.size();
		if (n > s2) n = s2;
		if (n < 0)n = 0;
		bool flag;
		for (int i = pos; i < s; i++)
		{
			if (str[i] == str2.str[0])
			{
				flag = true;
				for (int j = 1; j < n; j++)
				{
					if (str[i + j] != str2.str[j])
					{
						flag = false;
						break;
					}
				}
				if (flag) return i;
			}
		}
		return -1;
	}
	int rfind(String str2, int pos=0)
	{
		int s = size();
		pos = s-pos;
		int s2 = str2.size();
		bool flag;
		for (int i = pos; i >=0; i--)
		{
			if (str[i] == str2.str[0])
			{
				flag = true;
				for (int j = 1; j < s2; j++)
				{
					if (str[i + j] != str2.str[j])
					{
						flag = false;
						break;
					}
				}
				if (flag) return i;
			}
		}
		return -1;
	}
	int rfind(String str2, int pos, int n)
	{
		int s = size();
		pos = s - pos;
		if (pos == s) pos--;
		int s2 = str2.size();
		if (n > s2) n = s2;
		if (n < 0)n = 0;
		bool flag;
		for (int i = pos; i >=0; i--)
		{
			if (str[i] == str2.str[0])
			{
				flag = true;
				for (int j = 1; j < n; j++)
				{
					if (str[i + j] != str2.str[j])
					{
						flag = false;
						break;
					}
				}
				if (flag) return i;
			}
		}
		return -1;
	}
	int find_first_of(String str2, int pos = 0)
	{
		int s = size();
		int s2 = str2.size();
		for (int i = pos; i < s; i++)
		{
			for (int j = 0; j < s2; j++)
			{
				if (str[i] == str2.str[j]) return i;
			}
		}
		return -1;
	}
	int find_last_of(String str2, int pos = 0)
	{
		if (pos < 0) pos = 0;
		int s = size();
		int s2 = str2.size();
		for (int i = s-1; i >= pos; i--)
		{
			for (int j = 0; j < s2; j++)
			{
				if (str[i] == str2.str[j]) return i;
			}
		}
		return -1;
	}
	int find_forst_not_of(String str2, int pos = 0)
	{
		int s = size();
		int s2 = str2.size();
		bool flag;
		for (int i = pos; i < s; i++)
		{
			flag = true;
			for (int j = 0; j < s2; j++)
			{
				if (str[i] == str2.str[j])
				{
					flag = false;
					break;
				}
			}
			if (flag) return i;
		}
		return -1;
	}
	int find_last_not_of(String str2, int pos = 0)
	{
		if (pos < 0) pos = 0;
		int s = size();
		int s2 = str2.size();
		bool flag;
		for (int i = s - 1; i >= pos; i--)
		{
			flag = true;
			for (int j = 0; j < s2; j++)
			{
				if (str[i] == str2.str[j])
				{
					flag = false;
					break;
				}
			}
			if (flag) return i;
		}
		return -1;
	}
	char* c_str()
	{
		return str;
	}
};

