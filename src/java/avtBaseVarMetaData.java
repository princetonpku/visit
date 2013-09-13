// ***************************************************************************
//
// Copyright (c) 2000 - 2013, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-442911
// All rights reserved.
//
// This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or other materials provided with the distribution.
//  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
// LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
// DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ***************************************************************************

package llnl.visit;


// ****************************************************************************
// Class: avtBaseVarMetaData
//
// Purpose:
//    Contains metadata attributes associated with all mesh variables
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

public class avtBaseVarMetaData extends AttributeSubject
{
    private static int avtBaseVarMetaData_numAdditionalAtts = 5;

    public avtBaseVarMetaData()
    {
        super(avtBaseVarMetaData_numAdditionalAtts);

        name = new String("scalar");
        originalName = new String("");
        meshName = new String("mesh");
        validVariable = true;
        hideFromGUI = false;
    }

    public avtBaseVarMetaData(int nMoreFields)
    {
        super(avtBaseVarMetaData_numAdditionalAtts + nMoreFields);

        name = new String("scalar");
        originalName = new String("");
        meshName = new String("mesh");
        validVariable = true;
        hideFromGUI = false;
    }

    public avtBaseVarMetaData(avtBaseVarMetaData obj)
    {
        super(avtBaseVarMetaData_numAdditionalAtts);

        name = new String(obj.name);
        originalName = new String(obj.originalName);
        meshName = new String(obj.meshName);
        validVariable = obj.validVariable;
        hideFromGUI = obj.hideFromGUI;

        SelectAll();
    }

    public int Offset()
    {
        return super.Offset() + super.GetNumAdditionalAttributes();
    }

    public int GetNumAdditionalAttributes()
    {
        return avtBaseVarMetaData_numAdditionalAtts;
    }

    public boolean equals(avtBaseVarMetaData obj)
    {
        // Create the return value
        return ((name.equals(obj.name)) &&
                (originalName.equals(obj.originalName)) &&
                (meshName.equals(obj.meshName)) &&
                (validVariable == obj.validVariable) &&
                (hideFromGUI == obj.hideFromGUI));
    }

    // Property setting methods
    public void SetName(String name_)
    {
        name = name_;
        Select(0);
    }

    public void SetOriginalName(String originalName_)
    {
        originalName = originalName_;
        Select(1);
    }

    public void SetMeshName(String meshName_)
    {
        meshName = meshName_;
        Select(2);
    }

    public void SetValidVariable(boolean validVariable_)
    {
        validVariable = validVariable_;
        Select(3);
    }

    public void SetHideFromGUI(boolean hideFromGUI_)
    {
        hideFromGUI = hideFromGUI_;
        Select(4);
    }

    // Property getting methods
    public String  GetName() { return name; }
    public String  GetOriginalName() { return originalName; }
    public String  GetMeshName() { return meshName; }
    public boolean GetValidVariable() { return validVariable; }
    public boolean GetHideFromGUI() { return hideFromGUI; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(name);
        if(WriteSelect(1, buf))
            buf.WriteString(originalName);
        if(WriteSelect(2, buf))
            buf.WriteString(meshName);
        if(WriteSelect(3, buf))
            buf.WriteBool(validVariable);
        if(WriteSelect(4, buf))
            buf.WriteBool(hideFromGUI);
    }

    public void ReadAtts(int index, CommunicationBuffer buf)
    {
        switch(index)
        {
        case 0:
            SetName(buf.ReadString());
            break;
        case 1:
            SetOriginalName(buf.ReadString());
            break;
        case 2:
            SetMeshName(buf.ReadString());
            break;
        case 3:
            SetValidVariable(buf.ReadBool());
            break;
        case 4:
            SetHideFromGUI(buf.ReadBool());
            break;
        }
    }

    public String toString(String indent)
    {
        String str = new String();
        str = str + stringToString("name", name, indent) + "\n";
        str = str + stringToString("originalName", originalName, indent) + "\n";
        str = str + stringToString("meshName", meshName, indent) + "\n";
        str = str + boolToString("validVariable", validVariable, indent) + "\n";
        str = str + boolToString("hideFromGUI", hideFromGUI, indent) + "\n";
        return str;
    }


    // Attributes
    private String  name;
    private String  originalName;
    private String  meshName;
    private boolean validVariable;
    private boolean hideFromGUI;
}

