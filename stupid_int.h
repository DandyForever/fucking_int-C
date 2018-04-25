#include <iostream>
#include <ostream>
#include "errors.h"
#include "../exception/myexception.h"

class demoint
{

    private:
        static const int num_add;
        static const int num_sub;
        static const int num_mul;
        static const int num_div;
        static const int num_asg;
        static const std::string mes_add;
        static const std::string mes_sub;
        static const std::string mes_mul;
        static const std::string mes_div;
        static const std::string mes_asg;


        int value_      = 0;

        int count_add_  = 0;
        int count_sub_  = 0;
        int count_mul_  = 0;
        int count_div_  = 0;
        int count_asg_  = 0;

    public:


        class limit_exception
        {};

        demoint                  ();
        demoint                  (const int value);
        ~demoint                 ();

        void swap                (demoint& that);

        demoint& operator =      (const int value);
        demoint& operator =      (const demoint& that);

        demoint operator +                ();

        friend demoint operator +         (demoint& left, demoint& right)
        {
            if (left.count_add_ < left.num_add && right.count_add_ < left.num_add)
            {
                left.count_add_++;
                right.count_add_++;

                return demoint(left.value_ + right.value_);
            }

            else
            {
                std::cout << left.mes_add;
                MAKE_EXCEPTION(left.mes_add, LIM_ADD, nullptr);
            }
        }

        demoint& operator +=     (demoint& victim);
        demoint& operator +=     (const int value);

        demoint operator -      ();

        friend demoint operator -        (demoint& left, demoint& right)
        {
            if (left.count_sub_ < left.num_sub && right.count_sub_ < left.num_sub)
            {
                left.count_sub_++;
                right.count_sub_++;

                return demoint (left.value_ - right.value_);
            }

            else
            {
                std::cout << left.mes_sub;
                MAKE_EXCEPTION(left.mes_sub, LIM_SUB, nullptr);
            }
        }

        demoint& operator -=     (demoint& victim);
        demoint& operator -=     (const int value);

        friend demoint operator *        (demoint& left, demoint& right)
        {
            if (left.count_mul_ < left.num_mul && right.count_mul_ < left.num_mul)
            {
                left.count_mul_++;
                right.count_mul_++;

                return demoint (left.value_ * right.value_);
            }

            else
            {
                std::cout << left.mes_mul;
                MAKE_EXCEPTION(left.mes_mul, LIM_MUL, nullptr);
            }
        }
        demoint& operator *=     (demoint& victim);
        demoint& operator *=     (const int value);

        friend demoint operator /         (demoint& left, demoint& right)
        {
            if (left.count_div_ < left.num_div && right.count_div_ < left.num_div)
            {
                left.count_div_++;
                right.count_div_++;

                return demoint (left.value_ / right.value_);
            }

            else
            {
                std::cout << left.mes_div;
                MAKE_EXCEPTION(left.mes_div, LIM_DIV, nullptr);
            }
        }
        demoint& operator /=     (demoint& victim);
        demoint& operator /=     (const int value);

        int get_value            ();
};

const int demoint::num_add = 3;
const int demoint::num_sub = 3;
const int demoint::num_mul = 3;
const int demoint::num_div = 3;
const int demoint::num_asg = 3;
const std::string demoint::mes_add = "Sorry, but you have already used all your demo-additions\n";
const std::string demoint::mes_sub = "Sorry, but you have already used all your demo-subtractions\n";
const std::string demoint::mes_mul = "Sorry, but you have already used all your demo-multiplications\n";
const std::string demoint::mes_div = "Sorry, but you have already used all your demo-divisions\n";
const std::string demoint::mes_asg = "Sorry, but you have already used all your demo-assignments\n";


demoint::demoint        ():
    value_              (0),

    count_add_          (0),
    count_sub_          (0),
    count_mul_          (0),
    count_div_          (0),
    count_asg_          (0)

{}

demoint::demoint        (const int value):
    value_              (value),

    count_add_          (0),
    count_sub_          (0),
    count_mul_          (0),
    count_div_          (0),
    count_asg_          (0)

{}

demoint::~demoint       ()
{
    value_              = 0;

    count_add_          = 0;
    count_sub_          = 0;
    count_mul_          = 0;
    count_div_          = 0;
    count_asg_          = 0;
}

void demoint::swap               (demoint& that)
{
    std::swap (value_, that.value_);

    std::swap (count_add_, that.count_add_);
    std::swap (count_sub_, that.count_sub_);
    std::swap (count_mul_, that.count_mul_);
    std::swap (count_div_, that.count_div_);
    std::swap (count_asg_, that.count_asg_);
}

demoint& demoint::operator =     (const int value)
{
    if (count_asg_ < num_asg)
    {
        value_              = value;
        count_asg_++;

        return *this;
    }

    else
    {
        std::cout << mes_asg;
        MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
    }
}

demoint& demoint::operator =      (const demoint& that)
{
    if (count_asg_ < num_asg)
    {
        value_              = that.value_;
        count_asg_++;

        return *this;
    }

    else
    {
        std::cout << mes_asg;
        MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
    }
}

int demoint::get_value            ()
{
    return value_;
}

std::ostream& operator <<         (std::ostream& out, demoint& victim)
{
    out << victim.get_value ();

    return out;
}

demoint demoint::operator +             ()
{
    return demoint(value_);
}

demoint& demoint::operator +=          (const int value)
{
    if (count_add_ < num_add && count_asg_ < num_asg)
    {
        value_ += value;
        count_add_++;
        count_asg_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_add;
            MAKE_EXCEPTION(left.mes_add, LIM_ADD, nullptr);
        }
    }
}

demoint& demoint::operator +=          (demoint& victim)
{
    if (count_add_ < num_add && count_asg_ < num_asg && victim.count_add_ < num_add)
    {
        value_ += victim.value_;
        count_add_++;
        count_asg_++;
        victim.count_add_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_add;
            MAKE_EXCEPTION(left.mes_add, LIM_ADD, nullptr);
        }
    }
}

demoint demoint::operator -           ()
{
    return demoint (-value_);
}

demoint& demoint::operator -=          (const int value)
{
    if (count_sub_ < num_sub && count_asg_ < num_asg)
    {
        value_ -= value;
        count_sub_++;
        count_asg_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_sub;
            MAKE_EXCEPTION(left.mes_sub, LIM_SUB, nullptr);
        }
    }
}

demoint& demoint::operator -=          (demoint& victim)
{
    if (count_sub_ < num_sub && count_asg_ < num_asg && victim.count_sub_ < num_sub)
    {
        value_ -= victim.value_;
        count_sub_++;
        count_asg_++;
        victim.count_sub_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_sub;
            MAKE_EXCEPTION(left.mes_sub, LIM_SUB, nullptr);
        }
    }
}

demoint& demoint::operator *=          (const int value)
{
    if (count_mul_ < num_mul && count_asg_ < num_asg)
    {
        value_ *= value;

        count_mul_++;
        count_asg_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_mul;
            MAKE_EXCEPTION(left.mes_mul, LIM_MUL, nullptr);
        }
    }
}

demoint& demoint::operator *=          (demoint& victim)
{
    if (count_mul_ < num_mul && count_asg_ < num_asg && victim.count_mul_ < num_mul)
    {
        value_ *= victim.value_;

        count_mul_++;
        count_asg_++;
        count_mul_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_mul;
            MAKE_EXCEPTION(left.mes_mul, LIM_MUL, nullptr);
        }
    }
}

demoint& demoint::operator /=          (const int value)
{
    if (count_div_ < num_div && count_asg_ < num_asg)
    {
        value_ /= value;

        count_div_++;
        count_asg_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_div;
            MAKE_EXCEPTION(left.mes_div, LIM_DIV, nullptr);
        }
    }
}

demoint& demoint::operator /=          (demoint& victim)
{
    if (count_div_ < num_div && count_asg_ < num_asg && victim.count_div_ < num_div)
    {
        value_ /= victim.value_;

        count_div_++;
        count_asg_++;
        count_div_++;

        return *this;
    }

    else
    {
        if (count_asg_ >= num_asg)
        {
            std::cout << mes_asg;
            MAKE_EXCEPTION(left.mes_asg, LIM_ASG, nullptr);
        }

        else
        {
            std::cout << mes_div;
            MAKE_EXCEPTION(left.mes_div, LIM_DIV, nullptr);
        }
    }
}
