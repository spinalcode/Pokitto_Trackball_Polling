#define dir_UP 1
#define dir_DOWN 2
#define dir_LEFT 3
#define dir_RIGHT 4
#define dir_BUTTON 5
#define color_WHITE 1
#define color_RED 2
#define color_GREEN 3
#define color_BLUE 4
 
//Setup a new class for a Trackball Module
class Trackball
{
public:
    Trackball(PinName pin_btn, PinName pin_lft, PinName pin_rht, PinName pin_up, PinName pin_dwn, PinName pin_wht, PinName pin_grn, PinName pin_red, PinName pin_blu);
    unsigned int read(int dir);
    void write(unsigned int val, int color);
private:
//class sets up the pins
    DigitalIn _pin_btn;
    DigitalIn _pin_lft;
    DigitalIn _pin_rht;
    DigitalIn _pin_up;
    DigitalIn _pin_dwn;
    DigitalOut _pin_wht;
    DigitalOut _pin_grn;
    DigitalOut _pin_red;
    DigitalOut _pin_blu;
};
 
Trackball::Trackball(PinName pin_btn, PinName pin_lft, PinName pin_rht, PinName pin_up, PinName pin_dwn, PinName pin_wht, PinName pin_grn, PinName pin_red, PinName pin_blu)
    : _pin_btn(pin_btn), _pin_lft(pin_lft), _pin_rht(pin_rht), _pin_up(pin_up), _pin_dwn(pin_dwn), _pin_wht(pin_wht), _pin_grn(pin_grn), _pin_red(pin_red), _pin_blu(pin_blu)
{
       //initialize all LED pins to off.
 
    _pin_wht = 0;
    _pin_grn = 0;
    _pin_red = 0;
    _pin_blu = 0;
 
}
 
void Trackball::write(unsigned int val, int color)
 
    {
        if (color == color_WHITE){_pin_wht = val;}
        else if(color == color_BLUE){_pin_blu = val;}
        else if(color == color_GREEN){_pin_grn = val;}
        else if(color == color_RED){_pin_red = val;}
        else {printf("Invalid LED Color");}
    }
unsigned int Trackball::read(int dir)
 
    {
        unsigned int val;
        if(dir == dir_UP){val = _pin_up;}
        else if(dir == dir_DOWN){val = _pin_dwn;}
        else if(dir == dir_RIGHT){val = _pin_rht;}
        else if(dir == dir_LEFT){val = _pin_lft;}
        else if(dir == dir_BUTTON){val = _pin_btn;}
        return val;
        
    }