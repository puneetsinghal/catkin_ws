// Generated by gencpp from file p2os_msgs/SonarArray.msg
// DO NOT EDIT!


#ifndef P2OS_MSGS_MESSAGE_SONARARRAY_H
#define P2OS_MSGS_MESSAGE_SONARARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace p2os_msgs
{
template <class ContainerAllocator>
struct SonarArray_
{
  typedef SonarArray_<ContainerAllocator> Type;

  SonarArray_()
    : header()
    , ranges_count(0)
    , ranges()  {
    }
  SonarArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , ranges_count(0)
    , ranges(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _ranges_count_type;
  _ranges_count_type ranges_count;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _ranges_type;
  _ranges_type ranges;




  typedef boost::shared_ptr< ::p2os_msgs::SonarArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::p2os_msgs::SonarArray_<ContainerAllocator> const> ConstPtr;

}; // struct SonarArray_

typedef ::p2os_msgs::SonarArray_<std::allocator<void> > SonarArray;

typedef boost::shared_ptr< ::p2os_msgs::SonarArray > SonarArrayPtr;
typedef boost::shared_ptr< ::p2os_msgs::SonarArray const> SonarArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::p2os_msgs::SonarArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::p2os_msgs::SonarArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace p2os_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'p2os_msgs': ['/home/puneet/catkin_ws/src/p2os/p2os_msgs/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::p2os_msgs::SonarArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::p2os_msgs::SonarArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::p2os_msgs::SonarArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::p2os_msgs::SonarArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::p2os_msgs::SonarArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::p2os_msgs::SonarArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::p2os_msgs::SonarArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2984921c09aef26ad253c7629937a5bb";
  }

  static const char* value(const ::p2os_msgs::SonarArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2984921c09aef26aULL;
  static const uint64_t static_value2 = 0xd253c7629937a5bbULL;
};

template<class ContainerAllocator>
struct DataType< ::p2os_msgs::SonarArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "p2os_msgs/SonarArray";
  }

  static const char* value(const ::p2os_msgs::SonarArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::p2os_msgs::SonarArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header    header\n\
int32     ranges_count\n\
float64[] ranges\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::p2os_msgs::SonarArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::p2os_msgs::SonarArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.ranges_count);
      stream.next(m.ranges);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SonarArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::p2os_msgs::SonarArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::p2os_msgs::SonarArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "ranges_count: ";
    Printer<int32_t>::stream(s, indent + "  ", v.ranges_count);
    s << indent << "ranges[]" << std::endl;
    for (size_t i = 0; i < v.ranges.size(); ++i)
    {
      s << indent << "  ranges[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.ranges[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // P2OS_MSGS_MESSAGE_SONARARRAY_H
