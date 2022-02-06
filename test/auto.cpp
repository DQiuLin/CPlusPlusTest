#include "common.h"

class Device {

};

class DeveicesMap {
private:
    unordered_map<string, vector<Device *>> devicesMap;
public:
    const unordered_map<string, vector<Device *>>& GetDevicesMap() const {
        return devicesMap;
    }
};

int main () {
    DeveicesMap devicesMap;
    //默认是进行复制，需要显示的表示&
    const auto &umap = devicesMap.GetDevicesMap();
    return 0;
}