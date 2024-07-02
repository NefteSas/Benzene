class element
{
private:
    char _id[MAX_ELEMENT_LENGH];
    
    __int8 _charge;
public:
    char *get_char_id();
    element(const char id[], const __int8 charge);
};