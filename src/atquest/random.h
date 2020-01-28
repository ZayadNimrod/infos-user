class RNG
{
  public:
    RNG();
    void SetSeed(int s);
    int Next(int range);

  private:
    int seed;
    
};