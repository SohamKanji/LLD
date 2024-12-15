/**
 * Don't put too much into an interface, split into separate interfaces.
*/

struct Document;

/**
 * All concrete classes using this interface might not need to implement print, fax and scan at once.
*/
struct IMachine
{
    virtual void print(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
};

struct IPrinter
{
    virtual void print(Document& doc) = 0;
};

struct IScanner
{
    virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter
{
    void print(Document& doc) override;
};

struct Scanner : IScanner
{
    void scan(Document& doc) override;
};

struct BetterIMachine : IPrinter, IScanner
{

};

struct Machine : IMachine 
{
    IPrinter& m_printer;
    IScanner& m_scanner;

    Machine(IPrinter& printer, IScanner& scanner) : m_printer(printer), m_scanner(scanner)
    {

    }

    void print(Document& doc) override {
        m_printer.print(doc);
    }

    void scan(Document& doc) override {
        m_scanner.scan(doc);
    }
};





