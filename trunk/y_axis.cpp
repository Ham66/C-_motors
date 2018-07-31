#include <tango.h>
#include "y_axis.h"

y_axis::y_axis(string path_to_device) {
	y_axis_device = new Tango::DeviceProxy(path_to_device);
	position_attribute = y_axis_device->read_attribute(position_name);
}

void y_axis::set_position(double position_to_set) {
	try {
		Tango::DevVarDoubleArray *in = new Tango::DevVarDoubleArray();
		in->length(1);
		(*in)[0] = position_to_set;
		position_attribute << in;
		y_axis_device->write_attribute(position_attribute);
  	}
	catch (Tango::DevFailed &e) {
		Tango::Except::print_exception(e);
	}
	catch (CORBA::BAD_PARAM &e) {
		Tango::Except::print_exception(e);
	}
}

int y_axis::get_state() {
	try {
		state = y_axis_device->state();
		return state;
  	}
	catch (Tango::DevFailed &e) {
		Tango::Except::print_exception(e);
	}
}
