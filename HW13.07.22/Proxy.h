#pragma once

struct CashElement {
    int id;
    string data;
    string date;
};


class Proxy
{
    string path;
    LinkedList<CashElement> cash;

public:
    Proxy(string path) {
        this->path = path;
    }
    string getData(int id) {
        string str = "data not found";
        CashElement* el = cash.searchData(id);
        if (el != nullptr) {
            string strDate;
            ifstream in(path);
            if (in.is_open())
            {
                getline(in, strDate);
                if (el->date == strDate)
                {
                    str = el->data;
                }
                else
                {
                    cash.addToHead(serchInFile(id));
                    str = cash.getHead()->data;
                }
            }
        }
        else {
            cash.addToHead(serchInFile(id));
            str = cash.getHead()->data;
        }
        return str;
    }

private:
    CashElement* serchInFile(int id) {
        CashElement* element = nullptr;
        ifstream in(path);
        if (in.is_open()) {
            string str;
            string buf;
            string buf2 = "";
            string strDate = "";
            int n = NULL;
            int counter = 0;
            while (getline(in, str)) {
                if (counter == 0) {
                    strDate = str;
                    counter++;
                }
                else {
                    buf = "";
                    for (int i = 0; str[i] != ' '; i++) {
                        buf += str[i];
                    }
                    n = stringToInt(buf);
                    if (n == id) {
                        for (int i = buf.size() + 1; i < str.size(); i++) {
                            buf2 += str[i];
                        }
                        element = new CashElement{ id, buf2,strDate };
                    }
                }
            }
            in.close();

        }
        else {
            in.close();
            throw "file not found";
        }
        return element;

    }

    int stringToInt(string str) {
        int n = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            n *= 10;
            n += (str[i] - 48);
        }
        return n;
    }

    string intToString(int n) {
        string str = "";
        int k = 0;
        int n2 = n;
        while (n2 > 0) {
            n2 /= 10;
            k++;
        }
        for (int i = k - 1, l; i >= 0; i--) {
            l = n / pow(10, i);
            n = n - l * pow(10, i);
            str += l + 48;
        }
        return str;
    }


};

