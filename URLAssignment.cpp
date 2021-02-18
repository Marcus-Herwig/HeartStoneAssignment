#include <string>
#include <iostream>
#include <curl/curl.h>


using namespace std;
string contents = "";

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int numbytes = size*nmemb;
    // The data is not null-terminated, so get the last character, and replace
    // it with '\0'.
    char lastchar = *((char *) ptr + numbytes - 1);
    *((char *) ptr + numbytes - 1) = '\0';
    contents.append((char *)ptr);
    contents.append(1,lastchar);
    *((char *) ptr + numbytes - 1) = lastchar;  // Might not be necessary.
    return size*nmemb;
}

string retrieveURL(string url)
{
   CURL* curl = curl_easy_init();
    if(curl)
    {
        // Tell libcurl the URL
        curl_easy_setopt(curl,CURLOPT_URL, url.c_str() );
        // Tell libcurl what function to call when it has data
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data);
        // Do it!
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == 0)
        {
            cout << contents << endl;
            string temp = "";
            for(int i = 0; i < 5; i++)
            {
                temp += contents[i];
            }
            cout << temp << endl;
        }
        else
        {
            cerr << "Error: " << res << endl;
        }
    }
    return "";
}




class URL
{
    public:
    string url = "";
    URL(string source)
    {
        url = source;

    }
    string getContents()
    {
        contents = retrieveURL(url);
        return contents;
    }



    
};
int main(int argc, char *argv[])
{
    
    URL* u1 = new URL("https://www.google.com/");
    cout<<u1->getContents()<<endl;
}
