#ifndef INFO_PROVIDER_HPP
#define INFO_PROVIDER_HPP

#include <m4gfx/sis/defs.hpp>
#include <m4gfx/sis/types.h>
#include <m4gfx/sis/x_info.hpp>

#include <set>
#include <initializer_list>

namespace m4gfx
{

 
XINFOAPI class info_provider
{
protected:
    bool dirty = true;
    x_info info;
    
public:
    info_provider();
    
    info_provider(m4gfx::XINFOCLASS x_type);
    
    info_provider(x_info& _info);
/*        
    info_provider(const info_provider& rhs)
        : _tag(rhs._tag), info(rhs.info), dirty(rhs.dirty){}
*/        
    virtual ~info_provider() {}
    
    virtual const x_info& construct()  = 0;
     
    virtual const info_provider& operator=(info_provider& obj) {
        _tag = obj._tag;
        info= obj.info;
        return  *this;
    }
    
    const x_info& retrieve() {
        if(dirty){
            info = construct();
            dirty = false;
        }
        return info;
    }
 
    bool operator==(x_info const& rhs) const {
        return _tag == rhs.get_id();
    }
       
    bool operator==(info_provider const& rhs) const {
        return _tag == rhs.get_id();
    } 
    
    bool operator()( const info_provider& lhs, const info_provider& rhs) const { 
        return lhs._tag < rhs._tag;
    }
    
    const std::string& get_id() const { return _tag; }

protected:
    std::string _tag;
};

struct provider_cmp {
        bool operator()( const info_provider& lhs, const info_provider& rhs) const { 
        return lhs.get_id() < rhs.get_id();
    }
};

template<m4gfx::XINFOCLASS X = m4gfx::XIC_NONE > 
XINFOAPI class typed_info_provider : public info_provider {

private:
    //std::set<typed_info_provider, provider_cmp> _supplementals;
    std::set<m4gfx::x_info, m4gfx::xinfo_cmp> appendices;
    XINFOCLASS _type = X;
    
public:
    
    
    typedef typename std::set<m4gfx::x_info, m4gfx::xinfo_cmp>::iterator appendices_iterator;
    
    typed_info_provider() 
        : info_provider(_type) {}
     
    ~typed_info_provider() override {
        /*_supplementals.clear();*/
    } 

    const typed_info_provider& operator=(typed_info_provider& obj){
        info_provider::operator=(obj);
        _type = obj._type;
        info = obj.info;
        dirty = obj.dirty;
    }   
    
    virtual void build();
    
    const x_info& construct() override {
        if(dirty){
             build();
        }         
        for(auto _appendix: appendices){
            append(_appendix);
        }
        dirty = false;
        return info;

    }
    
    bool operator==(x_info const& rhs) const {
        return info_provider::operator ==(rhs);
    }
       
    bool operator==(typed_info_provider const& rhs) const {
        return info_provider::operator ==(rhs);
    }   
        
    bool operator()( const typed_info_provider& lhs, const typed_info_provider& rhs) const { 
        return info_provider::operator()(lhs,rhs);
    }
    
    XINFOCLASS get_type() { return _type; }
    
    
    void append( const m4gfx::x_info _info) {
        std::string path_string = std::string(JSON_PATH_SEPARATOR)+m4gfx::x_info_class_names[_info.get_type()] + std::string(JSON_PATH_SEPARATOR) + _info.get_id();
        info.insert_info(path_string,_info);
    }
    
    void add(const x_info info)  {
        appendices.insert(info);
    }

};
}

#endif // INFO_PROVIDER_HPP
