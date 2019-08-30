#ifndef X_INFO_HPP
#define X_INFO_HPP


#include <m4gfx/sis/defs.hpp>

#include <set>
#include <string>

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/property_tree/ptree.hpp>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

namespace m4gfx
{

class x_info
{
public:
    x_info() : _tag(boost::uuids::random_generator()()),
    _type(m4gfx::XIC_NONE){}
    
    x_info(m4gfx::XINFOCLASS x_type) : _tag(boost::uuids::random_generator()()),
    _type(x_type){}
    
    explicit x_info(m4gfx::XINFOCLASS type, boost::property_tree::ptree info, 
    std::set<std::string> attrs = std::set<std::string> () ) : _tag(boost::uuids::random_generator()()),
    _type(type), xis_info(info), _attrs(attrs){}
    
   ~x_info(){}

    bool operator==(x_info const& rhs) const {
        return _tag == rhs._tag;
    }
    
    bool operator()(const x_info& lhs, const x_info& rhs) const { 
        return lhs._tag < rhs._tag;
    }

    const x_info& operator=(x_info const& rhs) {
        _tag = rhs._tag;
        _type = rhs._type;
        xis_info = rhs.xis_info;        
        _attrs = rhs._attrs;
    }
    
    const boost::uuids::uuid& get_id() const { return _tag; }
    
    const m4gfx::XINFOCLASS get_type() const { return _type; }
    
    void set_type(m4gfx::XINFOCLASS t ) { _type = t; }
    
    const void add_attribute(std::string attr){
        _attrs.insert(attr);
    }
    
    const void insert_json(const rapidjson::Document& d);
    
    const void insert_info(std::string info_path, const x_info&  data);
    
    const boost::property_tree::ptree& get_data() const {
        return xis_info;
    }

private:
    m4gfx::XINFOCLASS _type;
    boost::uuids::uuid _tag;
    boost::property_tree::ptree xis_info;
    std::set<std::string> _attrs;
};

struct xinfo_cmp {
        bool operator()( const x_info& lhs, const x_info& rhs) const { 
        return lhs.get_id() < rhs.get_id();
    }
};

}

#endif // X_INFO_HPP
