#ifndef Y_AXIS_H_
#define Y_AXIS_H_

class y_axis {
public:
	y_axis(string path_to_device);
	void set_position(double position_to_set);
	int get_state();
private:
	Tango::DeviceProxy *y_axis_device;	
	Tango::DeviceAttribute position_attribute;
	double position;
	string position_name = "Position";
	int state;
};
#endif
