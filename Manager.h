#ifndef MANAGER_H
#define MANAGER_H


class Manager {
private:
    std::map<std::string, MultimediaPtr> multimediaTable;

public:
    bool saveAll(const std::string & filename) const;
    bool readAll(const std::string & filename);
};

#endif // MANAGER_H
