#ifndef  gen__uuid_h_
#define  gen__uuid_h_

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

inline auto random_uuid() -> std::string
{
    boost::uuids::uuid uuid{boost::uuids::random_generator()()};
    return boost::uuids::to_string(uuid);
}

#endif //gen__uuid_h_
