


class ITextDocument
{
    protected:
    virtual void page_break() = 0;
    virtual void page_rendering() = 0;
    virtual void document_rendering() = 0;
};