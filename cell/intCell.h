#include <string>
#include <iostream>

using namespace std;

class IntCell{
    string type;
    int value = 0;


public:
    /**
     * default constructor for IntCell
     * @param value
     * @param type
     */
    IntCell(int value=0,string type="");

    /**
     * setter cell value
     * @param value new cell value;
     * @return
     */
    int setValue(int value);

    /**
     * getter cell value
     * @return cell value
     */
    int getValue();
    /**
     * will be needed in future
     * @return cell type
     */
    string getType();

    /**
     * assignment operator overload
     * @param[in] other - other IntCell object
     * @return this
     */
    IntCell& operator =(const IntCell& other);
    /**
     * serializing object into string
     * @return string with serialized object
     */
    string serialize();

    /**
     *
     * @param[in] data serialized string
     * @param[out] error deSerialization errors (code: 1 bad file structure)
     * @return pointer to new cell created from serialized string
     */
    static IntCell* deSerialize(string data, int &error);


//
//    void setMask(string mask);
//    string getMask();




};


