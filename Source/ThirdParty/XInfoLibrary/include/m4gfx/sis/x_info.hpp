// Copyright 2019 Sheldon Robinson. All Rights Reserved.

#ifndef X_INFO_HPP
#define X_INFO_HPP

#include "xinfo/xinfo_api.h"
#include "m4gfx/sis/predef.hpp"
#include "m4gfx/sis/types.h"

#include <set>
#include <string>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/pointer.h>

namespace m4gfx
{

class XINFO_API x_info
{
public:
    x_info();
    
    x_info(m4gfx::XINFOCLASS x_type);
    
    explicit x_info(m4gfx::XINFOCLASS type, rapidjson::Document& info, 
    std::set<std::string> attrs = std::set<std::string> () );
    
    x_info(const x_info& rhs);
    
   ~x_info(){}

    bool operator==(x_info const& rhs) const {
        return _tag == rhs._tag;
    }
    
    bool operator()(const x_info& lhs, const x_info& rhs) const { 
        return lhs._tag < rhs._tag;
    }


    const x_info& operator=(const x_info& rhs) {
        _tag = rhs._tag;
        _type = rhs._type;
        xis_info.CopyFrom(rhs.xis_info, xis_info.GetAllocator());        
        _attrs = rhs._attrs;
        return *this;
    }

    XINFO_API  const std::string& get_id() const { return _tag; }
    
    XINFO_API  const m4gfx::XINFOCLASS get_type() const { return _type; }
   
    XINFO_API  void set_type(m4gfx::XINFOCLASS t ) { _type = t; }
    
    XINFO_API  const void add_attribute(std::string attr){
        _attrs.insert(attr);
    }

    XINFO_API  const void add_attribute(const std::set<std::string>& attrs) {
	_attrs.insert(attrs.cbegin(), attrs.cend());
    }
    
    XINFO_API   const void insert_json(const rapidjson::Document& d);
    
    XINFO_API  const void insert_info(const std::string info_path, const x_info&  data);

    XINFO_API  const rapidjson::Document& get_data() const {
        return xis_info;
    }

    XINFO_API  const std::set<std::string> get_fields() const  {
	return _attrs;
    }
    
    XINFO_API  const std::string get_data_as_string() const {
    	rapidjson::StringBuffer buffer;
    	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    	xis_info.Accept(writer);
    	return std::string(buffer.GetString());
    }
    
private:
    m4gfx::XINFOCLASS _type;
    std::string _tag;
    rapidjson::Document xis_info;
    std::set<std::string> _attrs;
};

struct xinfo_cmp {
        bool operator()( const x_info& lhs, const x_info& rhs) const { 
        return lhs.get_id() < rhs.get_id();
    }
};

}

#endif // X_INFO_HPP
