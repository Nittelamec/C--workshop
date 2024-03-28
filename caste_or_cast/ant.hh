#pragma once

#include <memory>

//! forward declaration
class Colony;

/*
 * Enum Class representing the stage of life for
 * an ant
 */
enum class DevelopmentStage : unsigned int
{
    // from the youngest to the oldest stage
    EGG = 0,
    LARVA,
    COCOON,
    ADULT
};

/*
 *  Base Class for every ant caste
 */
class Ant
{
public:
    //! delete constructor
    Ant() = delete;
    //! constructor
    Ant(std::shared_ptr<Colony> colony,
        DevelopmentStage stage = DevelopmentStage::EGG);
    //! copy constructor
    Ant(const Ant&);
    //! copy assignement
    Ant& operator=(const Ant&);
    //! default virtual destructor
    virtual ~Ant() = default;
    //! communicate with another Ant
    virtual bool communicate(std::weak_ptr<Ant> wk_receiver);
    //! attack given Ant and check if it is dead
    bool attack(std::weak_ptr<Ant> wk_ant);

    //! getter for passport_pheromone_ of Colony class
    uint32_t get_passport_pheromone();
    //! getter for stage_
    DevelopmentStage get_stage() const;
    //! getter for hp_
    int get_hp() const;
    //! setter for hp_
    void set_hp(int hp);
    //! getter for food_level_
    float get_food_level() const;
    //! increment by value food_level_
    void increment_food_level_by(float value);

protected:
    //! return by value the colony shared_ptr if not expired else throw error
    std::shared_ptr<Colony> check_colony_access();
    //! development stage
    DevelopmentStage stage_;
    //! Colony of this Ant
    std::weak_ptr<Colony> colony_;
    //! health points
    int hp_ = 4;
    //! represent the energy / food the ant ate for its
    // current Development stage
    float food_level_ = 0;
    //! friend class
    friend class Colony;
};
