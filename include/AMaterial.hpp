/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** AMaterial
*/

#ifndef AMATERIAL_HPP_
    #define AMATERIAL_HPP_
    #include "IMaterial.hpp"

class AMaterial : public IMaterial {
    public:
        AMaterial();
        ~AMaterial();
        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;
        class Error: public std::exception {
            public:
                Error(std::string error);
                const char *what() const noexcept override
                {
                    return _error.c_str();
                }
            private:
                std::string _error;
        };
    private:
};

#endif /* !AMATERIAL_HPP_ */
